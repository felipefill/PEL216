//
//  puzzle_state.cc
//  EightPuzzle
//
//  Created by Felipe Fill Cardoso on 7/21/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#include "puzzle_state.h"

namespace eightPuzzle {
    
    PuzzleState::PuzzleState() : state_(SquareMatrix<int>(kPuzzleSize)), blank_space_position_(-1, -1)
    {
    }
    
    PuzzleState::~PuzzleState()
    {
        
    }
    
    bool PuzzleState::operator == (PuzzleState & p)
    {
        bool equals = true;
        
        if (capacity() == p.capacity()) {
            for (int i = 0; i < square_capacity() && equals; i++) {
                for (int j = 0; j < square_capacity() && equals; j++) {
                    equals = ((*this)[i][j] == p[i][j]);
                }
            }
        }
        else {
            equals = false;
        }
            
        return equals;
    }
    
    PuzzleState & PuzzleState::operator + (PuzzleOperations operation)
    {
        //TODO: implement
        return *this;
    }
    
    Vector<int> PuzzleState::operator [] (int index) const
    {
        return state_[index];
    }
    
    Vector<int> & PuzzleState::operator [] (int index)
    {
        return state_[index];
    }
    
    int PuzzleState::capacity()
    {
        return state_.capacity();
    }
    
    int PuzzleState::square_capacity()
    {
        return state_.square_capacity();
    }
    
    ElementPosition & PuzzleState::blank_space_position()
    {
        if (blank_space_position_.line == -1 && blank_space_position_.row == -1)
        {
            blank_space_position_ = FindBlankSpace();
            //TODO: catch exception
        }
        
        return blank_space_position_;
    }
    
    ElementPosition & PuzzleState::FindBlankSpace()
    {
        ElementPosition * position = new ElementPosition(-1, -1);
        bool found = false;
        
        for (int i = 0; i < square_capacity() && !found; i++) {
            for (int j = 0; j < square_capacity() && !found; j++) {
                if ((*this)[i][j] == kBlankSpace) {
                    position->line = i;
                    position->row = j;
                    found = true;
                }
            }
        }
        
        if (!found) {
            delete position;
            //TODO: throw exception
        }
        
        return *position;
    }
    
}