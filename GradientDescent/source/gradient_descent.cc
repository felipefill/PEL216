/*
 * gradient_descent.cc
 *
 *  Created on: Aug 10, 2014
 *      Author: felipefill
 */

#include <cmath>
#include <iostream>
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
	//return 2 * x;
	return 3 * pow(x, 2) - 4 * x;
}

double GradientDescent::calculate()
{
	double g = 0.0f; //TODO: actually receive a g value
	double learning_factor = 0.1f; //TODO: actually receive a learning factor

	double x0 = initial_value_;
	double f0 = F(x0);

	double xi = x0;
	double fi = f0;

	while (!(fi > -0.00001f  && fi < 0.00001f)) {
		double si = DerivatedFunctionOn(xi);

		double xi_plus_1 = xi + learning_factor * (g - fi)/si;

		fi = F(xi_plus_1);
		xi = xi_plus_1;

		//cout << fi << endl;
	}

	cout << F(xi) << endl;

	return xi;
}


