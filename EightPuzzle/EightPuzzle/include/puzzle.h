//
//  puzzle.h
//  EightPuzzle
//
//  Created by Felipe Fill Cardoso on 7/21/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#ifndef PUZZLE_H_
#define PUZZLE_H_

namespace eightPuzzle
{
    class PuzzleState;
    
    class Puzzle
    {
      private:
        
      public:
        static PuzzleState * GenerateRandomState();
    };
}

#endif /* PUZZLE_H_ */
