//
//  depth_first_search.cc
//  EightPuzzle
//
//  Created by Felipe Fill on 8/3/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#include <iostream>
#include "../include/depth_first_search.h"
#include "../include/stack.h"

namespace eightPuzzle
{
    
    std::vector<PuzzleState*> DepthFirstSearch::DoSearch(PuzzleState * initial_state, PuzzleState * goal_state)
    {
        Stack<PuzzleState> to_expand = Stack<PuzzleState>();
        std::vector<PuzzleState *> visited_states;
        
        to_expand.Push(initial_state);
        visited_states.push_back(initial_state);
        
        long runs = 0;
        
        PuzzleState * current_element;
        while (!to_expand.IsEmpty()) {
            current_element = to_expand.Pop();
            
            if (*current_element == *goal_state) {
                return current_element->BuildPathToRoot();
            }
            
            std::vector<PuzzleState *> children = current_element->Children();
            for (int i = 0; i < children.size(); i++) {
                if (!ArrayContainsState(visited_states, children.at(i))) {
                    to_expand.Push(children.at(i));
                    visited_states.push_back(children.at(i));
                }
                else {
                    delete children.at(i);
                }
            }
            
            if (runs++ % 1000 == 0) {
                //std::cout << "Run no: " << runs-1 << std::endl;
            }
        }
        
        return std::vector<PuzzleState *>();
    }
    
}