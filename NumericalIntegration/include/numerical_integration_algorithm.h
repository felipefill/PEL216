/*
 * numerical_integration_algorithm.h
 *
 *  Created on: Aug 19, 2014
 *      Author: felipefill
 */

#ifndef NUMERICAL_INTEGRATION_ALGORITHM_H_
#define NUMERICAL_INTEGRATION_ALGORITHM_H_


class NumericalIntegrationBase
{
private:
	float interval_begin_;
	float interval_end_;
	int slicing_;
	double (*function_)(double);

public:
	NumericalIntegrationBase(double (*function)(double), float interval_begin, float interval_end, int slicing) {
		function_ = function;
		interval_begin_ = interval_begin;
		interval_end_ = interval_end;
		slicing_ = slicing;
	}

	virtual double Integrate() = 0;

};


#endif /* NUMERICAL_INTEGRATION_ALGORITHM_H_ */
