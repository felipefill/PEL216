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
        inline static bool CompareScoreAscending(PuzzleState * x, PuzzleState * y)
        {
            int x_score = Puzzle::EvaluateScoreForState(x);
            int y_score = Puzzle::EvaluateScoreForState(y);
            
            return x_score < y_score;
        }
        
        inline static bool CompareHeuristicDecreasing(PuzzleState * x, PuzzleState * y)
        {
            int x_heuristic = Puzzle::EvaluateHeuristicForState(x);
            int y_heuristic = Puzzle::EvaluateHeuristicForState(y);
            
            return x_heuristic > y_heuristic;
        }
        
      public:
        static PuzzleState * GenerateRandomState();
        static PuzzleState * GenerateEasyInitialState();
        static PuzzleState * GenerateTestInitialState();
        static PuzzleState * GenerateGoalState();
        
        static int EvaluateScoreForState(PuzzleState * state);
        static int EvaluateHeuristicForState(PuzzleState * state);
        
        static void OrderByScoreAscending(std::vector<PuzzleState *> & states);
        static void OrderByHeuristicDecreasing(std::vector<PuzzleState *> & states);
    };
}

#endif /* PUZZLE_H_ */
