//
//  puzzle_state.h
//  EightPuzzle
//
//  Created by Felipe Fill Cardoso on 7/21/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

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
        PuzzleState * parent_state_;
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
        std::vector<PuzzleState *> BuildPathToRoot();
        std::vector<PuzzleState *> Children();
        
        inline PuzzleState * parent_state() const { return parent_state_; }
        inline void set_parent_state(PuzzleState * parent_state) { parent_state_ = parent_state; }
        
    };
}

#endif /* PUZZLESTATE_H_ */
