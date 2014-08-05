//
//  not_implemented_exception.h
//  EightPuzzle
//
//  Created by Felipe Fill on 8/2/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#ifndef EightPuzzle_not_implemented_exception_h
#define EightPuzzle_not_implemented_exception_h

#ifndef INVALID_OPERATION_EXCEPTION_H_
#define INVALID_OPERATION_EXCEPTION_H_

#include <iostream>
#include <exception>

class NotImplementedException : public std::exception
{
    inline virtual const char *what() const throw() {
        return "This was not implemented yet!";
    }
};

#endif

#endif
