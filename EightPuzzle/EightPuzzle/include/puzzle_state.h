/*
 * PuzzleState.h
 *
 *  Created on: Jul 20, 2014
 *      Author: felipefill
 */

#ifndef PUZZLESTATE_H_
#define PUZZLESTATE_H_

#include "constants.h"
#include "square_matrix.h"
#include "puzzle_operations.h"
#include "element_position.h"

namespace eightPuzzle
{
    /*
        We will probably need to create methods such as performOperation so that we can change this state
     */
    
    class PuzzleState
    {
      private:
        SquareMatrix<int> state_;
        ElementPosition blank_space_position_;
        
        ElementPosition & FindBlankSpace();
        
        PuzzleState & copy();
        void SwitchValues (int *a, int *b);
        
      public:
        PuzzleState();
        ~PuzzleState();
        
        bool operator == (PuzzleState & p);
        PuzzleState & operator + (PuzzleOperations operation);
        Vector<int> operator [] (int index) const;
        Vector<int> & operator [] (int index);
        
        int capacity();
        int square_capacity();
        ElementPosition & blank_space_position();
        
        void Print();
        
    };
}

#endif /* PUZZLESTATE_H_ */
