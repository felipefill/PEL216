/*
 * adaptive_quadrature.cc
 *
 *  Created on: Sep 2, 2014
 *      Author: felipefill
 */

#include <cmath>
#include "../include/adaptive_quadrature.h"

AdaptiveQuadrature::AdaptiveQuadrature(double (*function)(double), float interval_begin, float interval_end)
	: NewtonCotes(function, interval_begin, interval_end, 100)
{
	set_threshold(pow(10, -13));
}

double AdaptiveQuadrature::Integrate()
{
	return IntegrateWithInterval(interval_begin_, interval_end_);
}

double AdaptiveQuadrature::IntegrateWithInterval(float begin, float end)
{
	float begin1 = begin;
	float end1 = (begin + end) / 2;
	double result1 = NewtonCotes(function_, begin1, end1, 100).Integrate();

	float begin2 = end1;
	float end2 = end;
	double result2 = NewtonCotes(function_, begin2, end2, 100).Integrate();

	double result;
	if (fabs(result2 - result1) > threshold()) {
		result = IntegrateWithInterval(begin1, end1) + IntegrateWithInterval(begin2, end2);
	}
	else {
		result = result1 + result2;
	}

	return result;
}
