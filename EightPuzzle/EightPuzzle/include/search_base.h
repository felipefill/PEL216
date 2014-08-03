//
//  search_base.h
//  EightPuzzle
//
//  Created by Felipe Fill on 8/2/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#ifndef EightPuzzle_search_base_h
#define EightPuzzle_search_base_h

#include "search_interface.h"

namespace eightPuzzle {
    
    class SearchBase : public SearchInterface
    {
      protected:
        bool ArrayContainsState(std::vector<PuzzleState *> array, PuzzleState *state);
        
      public:
        std::vector<PuzzleState*> DoSearch(PuzzleState * initial_state, PuzzleState * goal_state);
    };
    
}

#endif
