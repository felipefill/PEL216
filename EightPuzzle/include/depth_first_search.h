//
//  depth_first_search.h
//  EightPuzzle
//
//  Created by Felipe Fill on 8/3/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#ifndef EightPuzzle_depth_first_search_h
#define EightPuzzle_depth_first_search_h

#include "search_base.h"

namespace eightPuzzle {
    
    class DepthFirstSearch : public SearchBase
    {
      public:
        DepthFirstSearch(PuzzleState * initial_state);
        std::vector<PuzzleState *> DoSearch();
    };

}

#endif
