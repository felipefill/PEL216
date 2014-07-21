/*
 * PuzzleState.h
 *
 *  Created on: Jul 20, 2014
 *      Author: felipefill
 */

#ifndef PUZZLESTATE_H_
#define PUZZLESTATE_H_

#include "square_matrix.h"

#define kPuzzleSize 9 // If you ever change this, it must be a perfect square, keep that in mind.

namespace eightPuzzle
{
    /*
        We will probably need to create methods such as performOperation so that we can change this state
     */
    
    class PuzzleState
    {
      private:
        SquareMatrix<int> state;
        
      public:
        
    };
}

#endif /* PUZZLESTATE_H_ */
