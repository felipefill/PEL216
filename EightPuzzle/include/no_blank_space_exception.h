//
//  no_blank_space_exception.h
//  EightPuzzle
//
//  Created by Felipe Fill Cardoso on 7/21/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#ifndef NO_BLANK_SPACE_EXCEPTION_H_
#define NO_BLANK_SPACE_EXCEPTION_H_

#include <iostream>
#include <exception>

class NoBlankSpaceException : public std::exception
{
    inline virtual const char *what() const throw() {
        return "The puzzle has no blank spaces in it!";
    }
};

#endif