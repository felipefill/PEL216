/*
 * newton_cotes.h
 *
 *  Created on: Aug 19, 2014
 *      Author: felipefill
 */

#ifndef NEWTON_COTES_H_
#define NEWTON_COTES_H_

#include "numerical_integration_algorithm.h"

enum NewtonCotesIntegrationType
{
	kMidPointRule,
	kTrapezoidRule,
	kSimpsonRule
};


class NewtonCotes : public NumericalIntegrationBase
{
private:
	NewtonCotesIntegrationType integration_type_;

	double MidPointIntegration();
	double TrapezoidIntegration();
	double SimpsonIntegration();

	double MidPointError(double(*derivative)(double));
	double TrapezoidError(double(*derivative)(double));
	double SimpsonError(double(*derivative)(double));

public:
	NewtonCotes(double (*function)(double), float interval_begin, float interval_end, int slicing);
	~NewtonCotes() { }

	double Integrate();
	double ErrorWithDerivative(double(*derivative)(double));

	inline NewtonCotesIntegrationType integration_type() const { return integration_type_; }
	inline void set_integration_type (NewtonCotesIntegrationType type) { integration_type_ = type; }
};


#endif /* NEWTON_COTES_H_ */
