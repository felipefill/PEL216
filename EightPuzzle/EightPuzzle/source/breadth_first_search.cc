//
//  breadth_first_search.cc
//  EightPuzzle
//
//  Created by Felipe Fill on 8/2/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#include "../include/breadth_first_search.h"
#include "../include/queue.h"

namespace eightPuzzle {
    
    std::vector<PuzzleState> BreadthFirstSearch::DoSearch(PuzzleState * initial_state, PuzzleState * goal_state)
    {
        Queue<PuzzleState> states_to_expand;
        std::vector<PuzzleState> expanded_states;
        PuzzleState current_state = *initial_state;
        
        return current_state.BuildPathToRoot();
    }
    
}