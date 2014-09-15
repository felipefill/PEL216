/*
 * newton_cotes.cc
 *
 *  Created on: Aug 19, 2014
 *      Author: felipefill
 */

#include <cmath>
#include <iostream>
#include <exception>
#include "../include/newton_cotes.h"

NewtonCotes::NewtonCotes(double (*function)(double), float interval_begin, float interval_end, int slicing)
	: NumericalIntegrationBase(function, interval_begin, interval_end, slicing)
{
}

double NewtonCotes::Integrate()
{
	double result = 0.0f;
	int slice = 0;

	float previous_step = interval_begin();
	for (float current_step = interval_begin() + step_size(); slice < slicing(); current_step += step_size(), slice++) {
		result += (current_step - previous_step) * function((current_step + previous_step) / 2.0f);
		previous_step = current_step;
	}

	return result;
}

double NewtonCotes::ErrorWithDerivative(double(*derivative)(double))
{
	double result = 0.0f;
	int slice = 0;

	float previous_step = interval_begin();
	for (float current_step = interval_begin() + step_size(); slice < slicing(); current_step += step_size(), slice++) {
		result += (pow(current_step - previous_step, 3.0f) / 24.0f) * derivative(interval_begin());
	}

	return result;
}
