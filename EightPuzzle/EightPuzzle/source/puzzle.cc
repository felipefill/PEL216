//
//  puzzle.cc
//  EightPuzzle
//
//  Created by Felipe Fill Cardoso on 7/29/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "puzzle.h"
#include "puzzle_state.h"

namespace eightPuzzle
{
    class Random {
    public:
        Random(){
            srand( static_cast<unsigned int>(time(NULL)));
        }
        
        unsigned int operator()(unsigned int max){
            double tmp = static_cast<double>( rand() ) / static_cast<double>( RAND_MAX );
            return static_cast<unsigned int>( tmp * max );
        }
    };
    
    PuzzleState * Puzzle::GenerateRandomState()
    {
        PuzzleState * random_state = new PuzzleState();
        
        std::vector<int> available_values;
        for (int i = 0; i < kPuzzleSize; i++) {
            available_values.push_back(i);
        }
        
        std::random_shuffle(available_values.begin(), available_values.end(), Random());
        
        int square_capacity = sqrt(kPuzzleSize);
        int random_value_position = 0;
        
        for (int i = 0; i < square_capacity; i++) {
            for (int j = 0; j < square_capacity; j++) {
                (*random_state)[i][j] = available_values[random_value_position++];
            }
        }
        
        return random_state;
    }
    
    PuzzleState * Puzzle::GenerateEasyInitialState()
    {
        PuzzleState * state = new PuzzleState();
        
        (*state)[0][0] = 1; (*state)[0][1] = 2; (*state)[0][2] = 3;
        (*state)[1][0] = 4; (*state)[1][1] = 5; (*state)[1][2] = kBlankSpace;
        (*state)[2][0] = 7; (*state)[2][1] = 8; (*state)[2][2] = 6;
        
        return state;
    }
    
    PuzzleState * Puzzle::GenerateGoalState()
    {
        PuzzleState * state = new PuzzleState();
        
        (*state)[0][0] = 1; (*state)[0][1] = 2; (*state)[0][2] = 3;
        (*state)[1][0] = 4; (*state)[1][1] = 5; (*state)[1][2] = 6;
        (*state)[2][0] = 7; (*state)[2][1] = 8; (*state)[2][2] = kBlankSpace;
        
        return state;
    }
    
}
