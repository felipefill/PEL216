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
    private:
        void OrderByScoreDecreasing(std::vector<PuzzleState *> & states);
        
        inline static bool CompareScoreDecreasing(PuzzleState * x, PuzzleState * y)
        {
            int x_score = Puzzle::EvaluateScoreForState(x);
            int y_score = Puzzle::EvaluateScoreForState(y);
            
            return x_score > y_score;
        }
        
    public:
        HillClimbingSearch(PuzzleState * initial_state);
        std::vector<PuzzleState *> DoSearch();
    };
    
}

#endif