//
//  invalid_operation.h
//  EightPuzzle
//
//  Created by Felipe Fill Cardoso on 7/21/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#ifndef INVALID_OPERATION_EXCEPTION_H_
#define INVALID_OPERATION_EXCEPTION_H_

#include <iostream>
#include <exception>

class InvalidOperationException : public std::exception
{
    inline virtual const char *what() const throw() {
        return "You tried to perform an invalid operation!";
    }
};

#endif