/*
 * main.cc
 *
 *  Created on: Jul 20, 2014
 *      Author: felipefill
 */

#include <iostream>
#include <cstdlib>

#include "square_matrix.h"

using namespace eightPuzzle;

int main()
{
	SquareMatrix<int> matrix = SquareMatrix<int>(4);

	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[1][0] = 3;
	matrix[1][1] = 4;

    std::cout << matrix[0][0] << "  "  << matrix[0][1] << std::endl;
    std::cout << matrix[1][0] << "  "  << matrix[1][1] << std::endl;

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
