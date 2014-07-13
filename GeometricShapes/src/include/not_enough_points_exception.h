/*
 * not_enough_points_exception.h
 *
 *  Created on: Jul 12, 2014
 *      Author: felipefill
 */

#ifndef NOT_ENOUGH_POINTS_EXCEPTION_H_
#define NOT_ENOUGH_POINTS_EXCEPTION_H_

#include <iostream>
#include <exception>

class NotEnoughPointsException : public std::exception
{
	inline virtual const char *what() const throw() {
		return "There are not enough points for this operation!";
	}
};

#endif /* NOT_ENOUGH_POINTS_EXCEPTION_H_ */
