//
//  best_first_search.cc
//  EightPuzzle
//
//  Created by Felipe Fill on 8/3/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#include <iostream>
#include "../include/puzzle.h"
#include "../include/best_first_search.h"
#include "../include/stack.h"

namespace eightPuzzle
{
    
    std::vector<PuzzleState *> BestFirstSearch::DoSearch(PuzzleState *initial_state, PuzzleState *goal_state)
    {
        Stack<PuzzleState> states_to_visit = Stack<PuzzleState>();
        std::vector<PuzzleState *> visited_states;
        
        states_to_visit.Push(initial_state);
        visited_states.push_back(initial_state);
        
        int highest_score = 0;
        
        PuzzleState * current_state;
        while (!states_to_visit.IsEmpty()) {
            current_state = states_to_visit.Pop();
            
            int score = Puzzle::EvaluateScoreForState(current_state);
            if (score > highest_score) {
                highest_score = score;
                std::cout << "HIGHEST SCORE: " << highest_score << std::endl;
            }
            
            if (*current_state == *goal_state) {
                return current_state->BuildPathToRoot();
            }
            
            std::vector<PuzzleState *> children = current_state->Children();
            
            // This ordering will garantee that we have the highest score always on top of the stack
            Puzzle::OrderByScoreAscending(children);
            
            for (int i = 0; i < children.size(); i++) {
                if (!ArrayContainsState(visited_states, children.at(i))) {
                    states_to_visit.Push(children.at(i));
                    visited_states.push_back(children.at(i));
                }
                else {
                    delete children.at(i);
                }
            }
            
        }
        
        return std::vector<PuzzleState *>();
    }
    
}