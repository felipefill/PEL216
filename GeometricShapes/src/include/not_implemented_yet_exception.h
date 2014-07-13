/*
 * not_implemented_yet_exception.h
 *
 *  Created on: Jul 12, 2014
 *      Author: felipefill
 */

#ifndef NOT_IMPLEMENTED_YET_EXCEPTION_H_
#define NOT_IMPLEMENTED_YET_EXCEPTION_H_

#include <iostream>
#include <exception>

class NotImplementedException : public std::exception
{
	inline virtual const char *what() const throw() {
		return "Not implemented yet!";
	}
};

#endif /* NOT_IMPLEMENTED_YET_EXCEPTION_H_ */
