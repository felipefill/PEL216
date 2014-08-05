//
//  search_base.cc
//  EightPuzzle
//
//  Created by Felipe Fill on 8/2/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#include "../include/not_implemented_exception.h"
#include "../include/search_base.h"

namespace eightPuzzle {
    
    SearchBase::SearchBase(PuzzleState * initial_state)
    {
        set_initial_state(initial_state);
    }
    
    std::vector<PuzzleState*> SearchBase::DoSearch()
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