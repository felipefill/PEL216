//
//  hill_climbing_search.cc
//  EightPuzzle
//
//  Created by Felipe Fill Cardoso on 8/4/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#include "../include/puzzle.h"
#include "../include/stack.h"
#include "../include/hill_climbing_search.h"

namespace eightPuzzle
{
    
    HillClimbingSearch::HillClimbingSearch(PuzzleState * initial_state) : HeuristicSearch(initial_state) { }
    
    std::vector<PuzzleState *> HillClimbingSearch::DoSearch()
    {
        Stack<PuzzleState> states_to_visit = Stack<PuzzleState>();
        std::vector<PuzzleState *> visited_states;
        
        states_to_visit.Push(initial_state());
        visited_states.push_back(initial_state());
        
        PuzzleState * current_state;
        while (!states_to_visit.IsEmpty()) {
            current_state = states_to_visit.Pop();
            
            if (*current_state == *goal_state()) {
                return current_state->BuildPathToRoot();
            }
            
            std::vector<PuzzleState *> children = current_state->Children();
            
            if (children.size() > 0) {
                OrderByScoreDecreasing(children);
                
                if (!ArrayContainsState(visited_states, children.at(0))) {
                    states_to_visit.Push(children.at(0));
                    visited_states.push_back(children.at(0));
                }
            }
            
        }
        
        return std::vector<PuzzleState *>();
    }
    
    void HillClimbingSearch::OrderByScoreDecreasing(std::vector<PuzzleState *> & states)
    {
        std::sort(states.begin(), states.end(), HillClimbingSearch::CompareScoreDecreasing);
    }
    
}