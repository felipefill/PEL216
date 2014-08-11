/*
 * gradient_descent.cc
 *
 *  Created on: Aug 10, 2014
 *      Author: felipefill
 */

#include <cmath>
#include <iostream>
#include <exception>
#include "../include/gradient_descent.h"

using namespace std;

GradientDescent::GradientDescent(std::vector<int> function, double initial_value)
{
	function_ = function;
	initial_value_ = initial_value;
}

double GradientDescent::F(double x)
{
	double result = 0.0f;

	for (int i = function_.size() - 1; i >= 0; --i) {
		double partial = function_.at(i) * pow(x, i);
		result += partial;
	}

	return result;
}

double GradientDescent::DerivatedFunctionOn(double x)
{
	double result = 0.0f;
	double partial;

	for (int i = function_.size() - 1; i >= 0; --i) {
		if (i > 0) {
			partial = (function_.at(i) * i) * pow(x, i-1);
		}
		else {
			partial = 0.0f;
		}

		result += partial;
	}

	return result;
}

double GradientDescent::Calculate(double g, double learning_factor, long max_iterations)
{
	double x0 = initial_value_;
	double f0 = F(x0);

	double xi = x0;
	double fi = f0;

	long current_iteration = 0;

	while (!(fi > -0.00001f  && fi < 0.00001f)) {
		double si = DerivatedFunctionOn(xi);

		double xi_plus_1 = xi + learning_factor * (g - fi)/si;

		fi = F(xi_plus_1);
		xi = xi_plus_1;

		if (current_iteration++ == max_iterations) {
			throw exception();
		}
	}

	return xi;
}


