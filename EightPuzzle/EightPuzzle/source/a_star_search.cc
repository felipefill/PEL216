//
//  a_star_search.cc
//  EightPuzzle
//
//  Created by Felipe Fill Cardoso on 8/4/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#include <iostream>
#include "../include/puzzle.h"
#include "../include/stack.h"
#include "../include/a_star_search.h"

namespace eightPuzzle
{

    std::vector<PuzzleState *> AStarSearch::DoSearch(PuzzleState * initial_state, PuzzleState * goal_state)
    {
        std::vector<PuzzleState *> states_to_visit;
        std::vector<PuzzleState *> visited_states;
        
        states_to_visit.push_back(initial_state);
        visited_states.push_back(initial_state);
        
        long lowest_score = 1000000;
        
        PuzzleState * current_state;
        while (!states_to_visit.empty()) {
            current_state = states_to_visit.back();
            states_to_visit.pop_back();
            
            long score = Puzzle::EvaluateHeuristicForState(current_state);
            if (score < lowest_score) {
                lowest_score = score;
                //std::cout << "LOWEST HEURISTIC: " << lowest_score << std::endl;
            }
            
            if (*current_state == *goal_state) {
                return current_state->BuildPathToRoot();
            }
            
            std::vector<PuzzleState *> children = current_state->Children();
            
            for (int i = 0; i < children.size(); i++) {
                if (!ArrayContainsState(visited_states, children.at(i))) {
                    states_to_visit.push_back(children.at(i));
                    visited_states.push_back(children.at(i));
                }
                else {
                    delete children.at(i);
                }
            }
            
            Puzzle::OrderByHeuristicDecreasing(states_to_visit);
        }
        
        return std::vector<PuzzleState *>();
    }
    
}
