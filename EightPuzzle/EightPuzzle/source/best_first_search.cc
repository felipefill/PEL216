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
        std::vector<PuzzleState *> states_to_visit;
        std::vector<PuzzleState *> visited_states;
        
        states_to_visit.push_back(initial_state);
        visited_states.push_back(initial_state);
        
        int highest_score = 0;
        
        PuzzleState * current_state;
        while (!states_to_visit.empty()) {
            current_state = states_to_visit.back();
            states_to_visit.pop_back();
            
            int score = Puzzle::EvaluateScoreForState(current_state);
            if (score > highest_score) {
                highest_score = score;
                //std::cout << "HIGHEST SCORE: " << highest_score << std::endl;
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
            
            // This ordering will garantee that we have the highest score always on top of the stack
            Puzzle::OrderByScoreAscending(states_to_visit);
            
        }
        
        return std::vector<PuzzleState *>();
    }
    
}