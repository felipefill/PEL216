/*
 * adaptive_quadrature.cc
 *
 *  Created on: Sep 2, 2014
 *      Author: felipefill
 */

#include <cmath>
#include "../include/adaptive_quadrature.h"

AdaptiveQuadrature::AdaptiveQuadrature(double (*function)(double), float interval_begin, float interval_end)
	: NewtonCotes(function, interval_begin, interval_end, 1000)
{
	set_threshold(pow(10, -10));
}

double AdaptiveQuadrature::Integrate()
{
	double result;
	double error;

	slicing_ = kSlicingStep;

	double result_old = NewtonCotes::Integrate();

	do {
		slicing_ += kSlicingStep;

		result = NewtonCotes::Integrate();
		error = fabs(result - result_old);
		result_old = result;

	} while(error > threshold() && slicing() < kSlicingLimit);

	return slicing() < kSlicingLimit ? result : 0;
}
