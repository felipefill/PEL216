//
//  hill_climbing_search.h
//  EightPuzzle
//
//  Created by Felipe Fill Cardoso on 8/4/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#ifndef EightPuzzle_hill_climbing_search_h
#define EightPuzzle_hill_climbing_search_h

#include "search_base.h"

namespace eightPuzzle {
    
    class HillClimbingSearch : public SearchBase
    {
    public:
        std::vector<PuzzleState *> DoSearch(PuzzleState * initial_state, PuzzleState * goal_state);
    };
    
}

#endif