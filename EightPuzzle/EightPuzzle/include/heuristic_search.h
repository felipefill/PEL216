//
//  heuristic_search.h
//  EightPuzzle
//
//  Created by Felipe Fill Cardoso on 8/4/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#ifndef Eight_puzzle_heuristic_search_h_
#define Eight_puzzle_heuristic_search_h_

#include "search_base.h"

namespace eightPuzzle {
    
    class HeuristicSearch : public SearchBase
    {
      protected:
        static int  EvaluateScoreForState(PuzzleState * state);
        static long EvaluateHeuristicForState(PuzzleState * state);
        
      public:
        HeuristicSearch(PuzzleState * initial_state);
    };
    
}


#endif