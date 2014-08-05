//
//  heuristic_search.cc
//  EightPuzzle
//
//  Created by Felipe Fill Cardoso on 8/4/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#include "../include/heuristic_search.h"

namespace eightPuzzle
{
    
    HeuristicSearch::HeuristicSearch(PuzzleState * initial_state) : SearchBase(initial_state) { }

    int HeuristicSearch::EvaluateScoreForState(PuzzleState * state)
    {
        PuzzleState * goal_state = Puzzle::GenerateGoalState();
        int score = 0;
        
        if (state->square_capacity() == goal_state->square_capacity()) {
            for (int i = 0; i < state->square_capacity(); i++) {
                for (int j = 0; j < state->square_capacity(); j++) {
                    if ((*state)[i][j] == (*goal_state)[i][j]) {
                        score++;
                    }
                }
            }
        }
        
        return score;
    }
    
    long HeuristicSearch::EvaluateHeuristicForState(PuzzleState * state)
    {
        PuzzleState * goal_state = Puzzle::GenerateGoalState();
        int score = kPuzzleSize;
        long cost = 0;
        long heuristic = 1000000;
        
        if (state->square_capacity() == goal_state->square_capacity()) {
            for (int i = 0; i < state->square_capacity(); i++) {
                for (int j = 0; j < state->square_capacity(); j++) {
                    if ((*state)[i][j] == (*goal_state)[i][j]) {
                        score--;
                    }
                }
            }
            
            ElementPosition blank_space_current = state->blank_space_position();
            ElementPosition blank_space_goal = goal_state->blank_space_position();
            
            cost += abs(blank_space_current.row - blank_space_goal.row);
            cost += abs(blank_space_current.line - blank_space_goal.line);
            
            heuristic = cost + score;
        }
        
        return heuristic;
    }

}
