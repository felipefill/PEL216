//
//  best_first_search.h
//  EightPuzzle
//
//  Created by Felipe Fill on 8/3/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#ifndef EightPuzzle_best_first_search_h
#define EightPuzzle_best_first_search_h

#include "heuristic_search.h"

namespace eightPuzzle {
    
    class BestFirstSearch : public HeuristicSearch
    {
      private:
        void OrderByScoreAscending(std::vector<PuzzleState *> & states);
        
        inline static bool CompareScoreAscending(PuzzleState * x, PuzzleState * y)
        {
            int x_score = EvaluateScoreForState(x);
            int y_score = EvaluateScoreForState(y);
            
            return x_score < y_score;
        }
        
      public:
        BestFirstSearch(PuzzleState * initial_state);
        std::vector<PuzzleState *> DoSearch();
    };
    
}

#endif
