//
//  element_position.h
//  EightPuzzle
//
//  Created by Felipe Fill Cardoso on 7/21/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#ifndef ELEMENT_POSITION_H_
#define ELEMENT_POSITION_H_

typedef struct ElementPosition
{
    int line;
    int row;
    
    ElementPosition(int line, int row) : line(line), row(row) { }
    
} ElementPosition;

#endif