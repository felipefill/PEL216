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
    
    BreadthFirstSearch::BreadthFirstSearch(PuzzleState * initial_state) : SearchBase(initial_state) { }
    
    std::vector<PuzzleState*> BreadthFirstSearch::DoSearch()
    {
        Queue<PuzzleState> states_to_expand = Queue<PuzzleState>();
        std::vector<PuzzleState *> expanded_states;
        
        expanded_states.push_back(initial_state());
        states_to_expand.QueueItem(initial_state());

        PuzzleState * current_element;
        while (!states_to_expand.IsEmpty()) {
            
            current_element = states_to_expand.DequeueItem();
            
            if (*current_element == *goal_state()) {
                return current_element->BuildPathToRoot();
            }
            
            std::vector<PuzzleState *> children = current_element->Children();
            for (int i = 0; i < children.size(); i++) {
                
                if (!ArrayContainsState(expanded_states, children.at(i))) {
                    states_to_expand.QueueItem(children.at(i));
                    expanded_states.push_back(children.at(i));
                }
                else {
                    delete children.at(i);
                }
            }
        }
        
        return std::vector<PuzzleState *>();
    }
    
}