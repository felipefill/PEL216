//
//  a_star_search.cc
//  EightPuzzle
//
//  Created by Felipe Fill Cardoso on 8/4/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#include <algorithm>
#include "../include/a_star_search.h"

namespace eightPuzzle
{

    AStarSearch::AStarSearch(PuzzleState * initial_state) : HeuristicSearch(initial_state) { }
    
    std::vector<PuzzleState *> AStarSearch::DoSearch()
    {
        std::vector<PuzzleState *> states_to_visit;
        std::vector<PuzzleState *> visited_states;
        
        states_to_visit.push_back(initial_state());
        visited_states.push_back(initial_state());
        
        PuzzleState * current_state;
        while (!states_to_visit.empty()) {
            current_state = states_to_visit.back();
            states_to_visit.pop_back();
            
            if (*current_state == *goal_state()) {
                return current_state->BuildPathToRoot();
            }
            
            std::vector<PuzzleState *> children = current_state->Children();
            
            for (size_t i = 0; i < children.size(); i++) {
                if (!ArrayContainsState(visited_states, children.at(i))) {
                    states_to_visit.push_back(children.at(i));
                    visited_states.push_back(children.at(i));
                }
                else {
                    delete children.at(i);
                }
            }
            
            OrderByHeuristicDecreasing(states_to_visit);
        }
        
        return std::vector<PuzzleState *>();
    }
    
    void AStarSearch::OrderByHeuristicDecreasing(std::vector<PuzzleState *> & states)
    {
        std::sort(states.begin(), states.end(), AStarSearch::CompareHeuristicDecreasing);
    }
    
}
