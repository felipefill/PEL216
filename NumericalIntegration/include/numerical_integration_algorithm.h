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
protected:
	float interval_begin_;
	float interval_end_;
	int slicing_;
	float step_size_;
	double (*function_)(double);

public:
	NumericalIntegrationBase(double (*function)(double), float interval_begin, float interval_end, int slicing) {
		function_ = function;
		interval_begin_ = interval_begin;
		interval_end_ = interval_end;
		slicing_ = slicing;

		step_size_ = (interval_end_ - interval_begin_) / slicing_;
	}

	virtual ~NumericalIntegrationBase() { }

	virtual double Integrate() = 0;

	float interval_begin() const { return interval_begin_; }
	float interval_end() const { return interval_end_; }
	int slicing() const { return slicing_; }
	float step_size() const { return step_size_; }
	double function (double input) const { return function_(input); }

};


#endif /* NUMERICAL_INTEGRATION_ALGORITHM_H_ */
