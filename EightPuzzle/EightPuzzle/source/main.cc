//
//  main.cc
//  EightPuzzle
//
//  Created by Felipe Fill Cardoso on 7/21/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#include "../include/best_first_search.h"
#include "../include/breadth_first_search.h"
#include "../include/depth_first_search.h"
#include "../include/a_star_search.h"
#include "../include/hill_climbing_search.h"

using namespace eightPuzzle;

void ExecuteSearch(SearchBase * search_algorithm, bool debug_print, bool pause_after_execution);

int main()
{
    PuzzleState * initial_state = Puzzle::GenerateTestInitialState();
    
    bool print_debug = false;
    bool pause_after_execution = false;
    
    ExecuteSearch(new AStarSearch(initial_state), print_debug, pause_after_execution);
    ExecuteSearch(new BestFirstSearch(initial_state), print_debug, pause_after_execution);
    ExecuteSearch(new HillClimbingSearch(initial_state), print_debug, pause_after_execution);
    ExecuteSearch(new DepthFirstSearch(initial_state), print_debug, pause_after_execution);
    ExecuteSearch(new BreadthFirstSearch(initial_state), print_debug, pause_after_execution);
    
    delete initial_state;
    
	return 0;
}

void ExecuteSearch(SearchBase * search_algorithm, bool debug_print, bool pause_after_execution)
{
    std::vector<PuzzleState*> result;

    if (debug_print) {
        std::cout << "Starting search with initial state: " << std::endl;
        search_algorithm->initial_state()->Print();
    }
    
    clock_t begin = clock();
    
    SearchBase * search = dynamic_cast<AStarSearch *>(search_algorithm);
    
    if(search != nullptr) {
        std::cout << "A* SEARCH ALGORITHM~" << std::endl;
        result = ((AStarSearch *)search)->DoSearch();
    }
    else {
        search = dynamic_cast<HillClimbingSearch *>(search_algorithm);
        if (search != nullptr) {
            std::cout << "HILL-CLIMBING ALGORITHM~" << std::endl;
            result = ((HillClimbingSearch *)search)->DoSearch();
        }
        else {
            search = dynamic_cast<BestFirstSearch *>(search_algorithm);
            if (search != nullptr) {
                std::cout << "BEST-FIRST SEARCH ALGORITHM~" << std::endl;
                result = ((BestFirstSearch *)search)->DoSearch();
            }
            else {
                search = dynamic_cast<DepthFirstSearch *>(search_algorithm);
                if (search != nullptr) {
                    std::cout << "DEPTH-FIRST SEARCH ALGORITHM~" << std::endl;
                    result = ((DepthFirstSearch *)search)->DoSearch();
                }
                else {
                    search = dynamic_cast<BreadthFirstSearch *>(search_algorithm);
                    if (search != nullptr) {
                        std::cout << "BREADTH-FIRST SEARCH ALGORITHM~" << std::endl;
                        result = ((BreadthFirstSearch *)search)->DoSearch();
                    }
                }
            }
        }
    }
    
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    if (result.size() > 0) {
        if (debug_print) {
            std::cout << "Found this result:" << std::endl;
            for (int i = 0; i < result.size(); i++) {
                result.at(i)->Print();
            }
        }
        else {
            std::cout << "Found a result." << std::endl;
        }
    }
    else {
        std::cout << "Found no results." << std::endl;
    }
    
    std::cout << "TIME ELAPSED: " << elapsed_secs << " seconds" << std::endl;
    
    if (pause_after_execution) {
        std::cout << "Press ENTER to continue";
        std::cin.ignore(std::cin.rdbuf()->in_avail()+1);
    }
    
    std::cout << "\n\n" << std::endl;
    
    
}

