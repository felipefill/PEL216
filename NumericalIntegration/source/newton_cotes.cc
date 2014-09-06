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
	set_integration_type(kMidPointRule);
}

double NewtonCotes::Integrate()
{
	switch (integration_type()) {
		case kMidPointRule:
			return MidPointIntegration();
		case kTrapezoidRule:
			return TrapezoidIntegration();
		case kSimpsonRule:
			return SimpsonIntegration();
		default:
			throw std::exception();
	}
}

double NewtonCotes::ErrorWithDerivative(double(*derivative)(double))
{
	switch (integration_type()) {
		case kMidPointRule:
			return MidPointError(derivative);
		case kTrapezoidRule:
			return TrapezoidError(derivative);
		case kSimpsonRule:
			return SimpsonError(derivative);
		default:
			throw std::exception();
	}
}

double NewtonCotes::MidPointIntegration()
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

double NewtonCotes::TrapezoidIntegration()
{
	double result = 0.0f;
	int slice = 0;

	float previous_step = interval_begin();
	for (float current_step = interval_begin() + step_size(); slice < slicing(); current_step += step_size(), slice++) {
		result += (current_step - previous_step) * (function(current_step) + function(previous_step)) / 2.0f;
		previous_step = current_step;
	}

	return result;
}

double NewtonCotes::SimpsonIntegration()
{
	double result = 0.0f;
	int slice = 0;

	float previous_step = interval_begin();
	for (float current_step = interval_begin() + step_size(); slice < slicing(); current_step += step_size(), slice++) {
		result += (current_step - previous_step) * ((function(current_step) + (4.0f * function((current_step + previous_step) / 2.0f)) + function(previous_step)) / 6.0f);
		previous_step = current_step;
	}

	return result;
}


double NewtonCotes::MidPointError(double(*derivative)(double))
{
	double result = 0.0f;
	int slice = 0;

	float previous_step = interval_begin();
	for (float current_step = interval_begin() + step_size(); slice < slicing(); current_step += step_size(), slice++) {
		result += (pow(current_step - previous_step, 3.0f) / 24.0f) * derivative(interval_begin());
	}

	return result;
}

double NewtonCotes::TrapezoidError(double(*derivative)(double))
{
	double result = 0.0f;
	int slice = 0;

	float previous_step = interval_begin();
	for (float current_step = interval_begin() + step_size(); slice < slicing(); current_step += step_size(), slice++) {
		result += ((-1 * pow(current_step - previous_step, 3.0f) / 12.0f)) * derivative(interval_begin());
	}

	return result;
}

double NewtonCotes::SimpsonError(double(*derivative)(double))
{
	double result = 0.0f;
	int slice = 0;

	float previous_step = interval_begin();
	for (float current_step = interval_begin() + step_size(); slice < slicing(); current_step += step_size(), slice++) {
		result += ((-1 * pow(current_step - previous_step, 5.0f) / 2880.0f)) * derivative(interval_begin());
	}

	return result;
}
