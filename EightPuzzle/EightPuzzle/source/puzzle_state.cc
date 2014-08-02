//
//  puzzle_state.cc
//  EightPuzzle
//
//  Created by Felipe Fill Cardoso on 7/21/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#include "puzzle_state.h"
#include "../include/no_blank_space_exception.h"
#include "../include/invalid_opeartion_exception.h"

namespace eightPuzzle {
    
    PuzzleState::PuzzleState() : state_(SquareMatrix<int>(kPuzzleSize)), blank_space_position_(-1, -1)
    {
        set_parent_state(nullptr);
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
        int line = blank_space_position().line;
        int row = blank_space_position().row;
        
        PuzzleState * result = &copy();
        
        switch (operation) {
            case kMoveBlankSpaceUp:
                if (line > 0 && line <= square_capacity()) {
                    SwitchValues(&(*result)[line - 1][row], &(*result)[line][row]);
                    result->blank_space_position_.line -= 1;
                }
                else {
                    /*
                        The first condition tests that we will not be going out of bounds;
                        The second one tests if we ARE out of bounds.
                     */
                    throw InvalidOpeartionException();
                }
                break;
                
            case kMoveBlankSpaceDown:
                if (line >= 0 && line < square_capacity()) {
                    SwitchValues(&(*result)[line + 1][row], &(*result)[line][row]);
                    result->blank_space_position_.line += 1;
                }
                else {
                    /*
                        The first condition tests if we ARE out of bounds;
                        The second one tests if we will be going out of bounds.
                     */
                    throw InvalidOpeartionException();
                }
                break;
                
            case kMoveBlankSpaceToTheLeft:
                if (row > 0 && row <= square_capacity()) {
                    SwitchValues(&(*result)[line][row - 1], &(*result)[line][row]);
                    result->blank_space_position_.row -= 1;
                }
                else {
                    throw InvalidOpeartionException();
                }
                break;
                
            case kMoveBlankSpaceToTheRight:
                if (row >= 0 && row < square_capacity()) {
                    SwitchValues(&(*result)[line][row + 1], &(*result)[line][row]);
                    result->blank_space_position_.row += 1;
                }
                else {
                    throw InvalidOpeartionException();
                }
                break;
                
            default:
                break;
        }
        
        return *result;
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
        }
        
        return blank_space_position_;
    }
    
    void PuzzleState::Print()
    {
        for (int i = 0; i < square_capacity(); i++) {
            for (int j = 0; j < square_capacity(); j++) {
                std::cout << (*this)[i][j] << "  ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    
    std::vector<PuzzleState*> PuzzleState::BuildPathToRoot()
    {
        std::vector<PuzzleState*> solution;
        solution.insert(solution.begin(), this);
        
        //TODO: look for other states
        
        return solution;
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
            throw NoBlankSpaceException();
        }
        
        return *position;
    }
    
    PuzzleState & PuzzleState::copy()
    {
        PuzzleState * copy = new PuzzleState(*this);
        
        return *copy;
    }
    
    void PuzzleState::SwitchValues (int * a, int * b)
    {
        int aux = *a;
        *a = *b;
        *b = aux;
    }
    
}