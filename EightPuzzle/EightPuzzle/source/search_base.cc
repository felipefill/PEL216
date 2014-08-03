//
//  search_base.cc
//  EightPuzzle
//
//  Created by Felipe Fill on 8/2/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#include "../include/search_base.h"
#include "../include/not_implemented_exception.h"

namespace eightPuzzle {
    
    std::vector<PuzzleState*> SearchBase::DoSearch(PuzzleState * initial_state, PuzzleState * goal_state)
    {
        throw NotImplementedException();
    }
    
    bool SearchBase::ArrayContainsState(std::vector<PuzzleState *> array, PuzzleState *state)
    {
        for (int i = 0; i < array.size(); i++) {
            if (*array.at(i) == *state) {
                return true;
            }
        }
        
        return false;
    }
    
}