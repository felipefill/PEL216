//
//  puzzle.h
//  EightPuzzle
//
//  Created by Felipe Fill Cardoso on 7/21/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#ifndef PUZZLE_H_
#define PUZZLE_H_

#include <iostream>
#include "puzzle_state.h"

namespace eightPuzzle
{
    class Puzzle
    {
      public:
        static PuzzleState * GenerateRandomState();
        static PuzzleState * GenerateEasyInitialState();
        static PuzzleState * GenerateTestInitialState();
        static PuzzleState * GenerateGoalState();
        
        static int EvaluateScoreForState(PuzzleState * state);
        static long EvaluateHeuristicForState(PuzzleState * state);
    };
}

#endif /* PUZZLE_H_ */
