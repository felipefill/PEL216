//
//  best_first_search.h
//  EightPuzzle
//
//  Created by Felipe Fill on 8/3/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#ifndef EightPuzzle_best_first_search_h
#define EightPuzzle_best_first_search_h

#include "search_base.h"

namespace eightPuzzle {
    
    class BestFirstSearch : public SearchBase
    {
      public:
        std::vector<PuzzleState *> DoSearch(PuzzleState * initial_state, PuzzleState * goal_state);
    };
    
}

#endif