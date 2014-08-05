//
//  hill_climbing_search.h
//  EightPuzzle
//
//  Created by Felipe Fill Cardoso on 8/4/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#ifndef EightPuzzle_hill_climbing_search_h
#define EightPuzzle_hill_climbing_search_h

#include "heuristic_search.h"

namespace eightPuzzle {
    
    class HillClimbingSearch : public HeuristicSearch
    {
    private:
        void OrderByScoreDecreasing(std::vector<PuzzleState *> & states);
        
        inline static bool CompareScoreDecreasing(PuzzleState * x, PuzzleState * y)
        {
            int x_score = EvaluateScoreForState(x);
            int y_score = EvaluateScoreForState(y);
            
            return x_score > y_score;
        }
        
    public:
        HillClimbingSearch(PuzzleState * initial_state);
        std::vector<PuzzleState *> DoSearch();
    };
    
}

#endif