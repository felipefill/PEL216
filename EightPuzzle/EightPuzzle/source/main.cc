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
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

#include "square_matrix.h"
#include "puzzle_state.h"
#include "puzzle.h"
#include "../include/breadth_first_search.h"

using namespace eightPuzzle;

int main()
{
    BreadthFirstSearch * search = new BreadthFirstSearch();

    PuzzleState * initial_state = Puzzle::GenerateRandomState();
    PuzzleState * goal_state = Puzzle::GenerateGoalState();

    std::vector<PuzzleState*> result = search->DoSearch(initial_state, goal_state);

    std::cout << "\n\n" << std::endl;
    if (result.size() > 0) {
        std::cout << "Found this result: " << std::endl;
        for (int i = 0; i < result.size(); i++) {
            result.at(i)->Print();
        }
    }
    else {
        std::cout << "Found no results for initial state:" << std::endl;
        initial_state->Print();
    }

    delete initial_state;
    delete goal_state;
    delete search;
    
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


//    for (int i = 0; i < 100000; i++) {
//        PuzzleState * state = Puzzle::GenerateRandomState();
//
//        state->Print();
//        delete state;
//
//        std::this_thread::sleep_for (std::chrono::milliseconds(200));
//    }

//    state = state + kMoveBlankSpaceToTheLeft;
//    state.Print();
//
//    state = state + kMoveBlankSpaceUp;
//    state.Print();
//
//    state = state + kMoveBlankSpaceToTheRight;
//    state.Print();
//
//    state = state + kMoveBlankSpaceDown;
//    state.Print();