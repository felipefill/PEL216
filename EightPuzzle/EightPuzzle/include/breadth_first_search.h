//
//  breadth_first_search.h
//  EightPuzzle
//
//  Created by Felipe Fill Cardoso on 7/29/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

/*

 You will need a queue for this.
 - Open first element, check if it's the solution, if not then add its nodes to the queue and loop.
 - Keep track of the nodes you've opened so far, that way you can backtrack as fast as possible if a state is duplicated.

 (Largura)
 
*/

#ifndef BREADTH_FIRST_SEARCH_H_
#define BREADTH_FIRST_SEARCH_H_

#include "search_base.h"

namespace eightPuzzle {
  
      class BreadthFirstSearch : public SearchBase
      {
        public:
          std::vector<PuzzleState*> DoSearch(PuzzleState * initial_state, PuzzleState * goal_state);
      };

}

#endif