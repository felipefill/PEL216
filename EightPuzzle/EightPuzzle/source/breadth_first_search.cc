//
//  breadth_first_search.cc
//  EightPuzzle
//
//  Created by Felipe Fill on 8/2/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#include <iostream>
#include "../include/breadth_first_search.h"
#include "../include/queue.h"

namespace eightPuzzle {
    
    std::vector<PuzzleState*> BreadthFirstSearch::DoSearch(PuzzleState * initial_state, PuzzleState * goal_state)
    {
        Queue<PuzzleState> states_to_expand = Queue<PuzzleState>();
        std::vector<PuzzleState *> expanded_states;
        
        expanded_states.push_back(initial_state);
        states_to_expand.QueueItem(initial_state);

        PuzzleState * current_element;
        long runs = 0;
        while (!states_to_expand.IsEmpty()) {
            
            current_element = states_to_expand.DequeueItem();
//            std::cout << "dequeue: " << std::endl;
//            current_element->Print();
            
            if (*current_element == *goal_state) {
                return current_element->BuildPathToRoot();
            }
            
            std::vector<PuzzleState *> children = current_element->Children();
            for (int i = 0; i < children.size(); i++) {
//                std::cout << "was child expanded before?" << std::endl;
//                children.at(i)->Print();
                
                if (!ArrayContainsState(expanded_states, children.at(i))) {
//                    std::cout << "NO" << std::endl;
                    states_to_expand.QueueItem(children.at(i));
                    expanded_states.push_back(children.at(i));
                }
                else {
//                    std::cout << "YES" << std::endl;
                    delete children.at(i);
                }
            }
            
            if (runs++ % 1000 == 0) {
                std::cout << "Run no: " << runs-1 << std::endl;
            }
        }
        
        return std::vector<PuzzleState *>();
    }
    
    bool BreadthFirstSearch::ArrayContainsState(std::vector<PuzzleState *> array, PuzzleState *state)
    {
        for (int i = 0; i < array.size(); i++) {
            if (*array.at(i) == *state) {
                return true;
            }
        }
        
        return false;
    }
    
}