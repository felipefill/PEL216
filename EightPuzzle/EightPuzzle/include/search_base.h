//
//  search_base.h
//  EightPuzzle
//
//  Created by Felipe Fill on 8/2/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#ifndef EightPuzzle_search_base_h
#define EightPuzzle_search_base_h

#include "search_interface.h"
#include "puzzle.h"

namespace eightPuzzle {
    
    class SearchBase : public SearchInterface
    {
      protected:
        PuzzleState * initial_state_;
        
        bool ArrayContainsState(std::vector<PuzzleState *> array, PuzzleState *state);
        
      public:
        SearchBase(PuzzleState * initial_state);
        
        std::vector<PuzzleState*> DoSearch();
        
        inline PuzzleState * initial_state() const { return initial_state_; };
        inline void set_initial_state(PuzzleState * initial_state) { initial_state_ = initial_state; }
        
        inline PuzzleState * goal_state() const { return Puzzle::GenerateGoalState(); }
    };
    
}

#endif
