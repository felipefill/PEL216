//
//  a_star_search.h
//  EightPuzzle
//
//  Created by Felipe Fill Cardoso on 8/4/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#ifndef EightPuzzle_a_star_search_h
#define EightPuzzle_a_star_search_h

#include "search_base.h"

namespace eightPuzzle {
    
    class AStarSearch : public SearchBase
    {   
    public:
        AStarSearch(PuzzleState * initial_state);
        std::vector<PuzzleState *> DoSearch();
    };
    
}

#endif