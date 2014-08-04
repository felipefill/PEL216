//
//  puzzle.h
//  EightPuzzle
//
//  Created by Felipe Fill Cardoso on 7/21/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#ifndef PUZZLE_H_
#define PUZZLE_H_

#include <cstdlib>
#include <iostream>
#include "puzzle_state.h"

namespace eightPuzzle
{
    class Puzzle
    {
      private:
        inline static bool compare(PuzzleState * x, PuzzleState * y)
        {
            int x_score = Puzzle::EvaluateScoreForState(x);
            int y_score = Puzzle::EvaluateScoreForState(y);
            
            return x_score < y_score;
        }
        
      public:
        static PuzzleState * GenerateRandomState();
        static PuzzleState * GenerateEasyInitialState();
        static PuzzleState * GenerateTestInitialState();
        static PuzzleState * GenerateGoalState();
        
        static int EvaluateScoreForState(PuzzleState * state);
        static void OrderByScoreAscending(std::vector<PuzzleState *> & states);
    };
}

#endif /* PUZZLE_H_ */
