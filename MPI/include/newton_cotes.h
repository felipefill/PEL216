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
	NewtonCotes(double (*function)(double), float interval_begin, float interval_end, int slicing);
	~NewtonCotes() { }

	double Integrate();
	double ErrorWithDerivative(double(*derivative)(double));
};


#endif /* NEWTON_COTES_H_ */
