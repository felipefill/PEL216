/*
 * points_overflow_exception.h
 *
 *  Created on: Jul 12, 2014
 *      Author: felipefill
 */

#ifndef POINTS_OVERFLOW_EXCEPTION_H_
#define POINTS_OVERFLOW_EXCEPTION_H_

#include <iostream>
#include <exception>

class PointsOverflowException : public std::exception
{
	inline virtual const char *what() const throw() {
		return "There are already too many points!";
	}
};


#endif /* POINTS_OVERFLOW_EXCEPTION_H_ */
