/*
 * newton_cotes.h
 *
 *  Created on: Aug 19, 2014
 *      Author: felipefill
 */

#ifndef NEWTON_COTES_H_
#define NEWTON_COTES_H_

#include "numerical_integration_algorithm.h"

class NewtonCotes : public NumericalIntegrationBase
{
public:
	NewtonCotes(double (*function)(double), float interval_begin, float interval_end, int slicing)
		: NumericalIntegrationBase(function, interval_begin, interval_end, slicing) { }

	double Integrate();
};


#endif /* NEWTON_COTES_H_ */
