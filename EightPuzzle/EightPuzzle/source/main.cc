/*
 * main.cc
 *
 *  Created on: Jul 20, 2014
 *      Author: felipefill
 */

#include <iostream>
#include <cstdlib>

#include "square_matrix.h"
#include "puzzle_state.h"

using namespace eightPuzzle;

int main()
{
    PuzzleState state = PuzzleState();

	state[0][0] = 1;
	state[0][1] = 2;
	state[1][0] = 3;
	state[1][1] = kBlankSpace;
    
    PuzzleState state2 = PuzzleState();
    
    state2[0][0] = 1;
    state2[0][1] = 2;
    state2[1][0] = 3;
    state2[1][1] = kBlankSpace;
    
    if (state == state2)
        std::cout << "true" << std::endl;
    
    std::cout << state.blank_space_position().line << " " << state.blank_space_position().row << std::endl;

    std::cout << state[0][0] << "  "  << state[0][1] << std::endl;
    std::cout << state[1][0] << "  "  << state[1][1] << std::endl;

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
