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

double NewtonCotes::MidPointIntegration()
{
	double result = 0.0f;
	int slice = 0;

	for (float current_step = interval_begin(); slice < slicing(); current_step += step_size(), slice++) {
		result += step_size() * function(((current_step * 2.0f) + step_size()) / 2.0f);
	}

	return result;
}

double NewtonCotes::TrapezoidIntegration()
{
	double result = 0.0f;
	int slice = 0;

	for (float current_step = interval_begin(); slice < slicing(); current_step += step_size(), slice++) {
		result += step_size() * ((function(current_step) + function(current_step + step_size())) / 2.0f);
	}

	return result;
}

double NewtonCotes::SimpsonIntegration()
{
	double result = 0.0f;
	int slice = 0;

	for (float current_step = interval_begin(); slice < slicing(); current_step += step_size(), slice++) {
		result += step_size() * ((function(current_step) + (4.0f * function(((current_step*2.0f) + step_size()) / 2.0f)) + function(current_step + step_size())) / 6.0f);
	}

	return result;
}

