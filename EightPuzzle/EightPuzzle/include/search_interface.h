//
//  search_interface.h
//  EightPuzzle
//
//  Created by Felipe Fill Cardoso on 7/29/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#ifndef SEARCH_INTERFACE_H_
#define SEARCH_INTERFACE_H_

namespace eightPuzzle {
  class PuzzleState;
    
  class SearchInterface
  {
    public:
      virtual std::vector<PuzzleState> DoSearch(PuzzleState & initial_state, PuzzleState & goal_state) = 0;
  };
      
}

#endif
