/*
 * gradient_descent.h
 *
 *  Created on: Aug 10, 2014
 *      Author: felipefill
 */

#ifndef GRADIENT_DESCENT_H_
#define GRADIENT_DESCENT_H_

#include <vector>

class GradientDescent
{
  private:
	std::vector<int> function_;
	double initial_value_;

	double F(double x);
	double DerivatedFunctionOn(double x);
  public:
	GradientDescent(std::vector<int> function, double initial_value);
	double calculate();
};

#endif /* GRADIENT_DESCENT_H_ */
