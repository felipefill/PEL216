//
//  main.cc
//  EightPuzzle
//
//  Created by Felipe Fill Cardoso on 7/21/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <exception>

#include "square_matrix.h"
#include "puzzle_state.h"

using namespace eightPuzzle;

int main()
{
    PuzzleState state = PuzzleState();

	state[0][0] = 1;
	state[0][1] = 2;
    state[0][2] = 8;
	state[1][0] = 3;
	state[1][1] = kBlankSpace;
    state[1][2] = 6;
    state[2][0] = 4;
    state[2][1] = 5;
    state[2][2] = 7;
    

    state.Print();
    
    state = state + kMoveBlankSpaceToTheLeft;
    state.Print();
    
    state = state + kMoveBlankSpaceUp;
    state.Print();
    
    state = state + kMoveBlankSpaceToTheRight;
    state.Print();
    
    state = state + kMoveBlankSpaceDown;
    state.Print();

	return 0;
}

/***
 *
 * There will be many methods to solve the puzzle.
 * All of them (so far) are search methods, such as BFS, A* and Hill-climbing.
 *
 * We will need a class to represent the puzzle (in its current state).
 * Also we need something to generate possible states
 * aaaaand some kind of data structure to hold the next states...
 * the next states are linked to the kind of solution that we will use
 * but we can generate the next possible states within the board/puzzle class.
 *
 *
 *
 */
