/*
 * adaptive_quadrature_integration.h
 *
 *  Created on: Sep 2, 2014
 *      Author: felipefill
 */

#ifndef ADAPTIVE_QUADRATURE_INTEGRATION_H_
#define ADAPTIVE_QUADRATURE_INTEGRATION_H_

#include "newton_cotes.h"

#define kSlicingStep 100
#define kSlicingLimit 1000000

class AdaptiveQuadrature : public NewtonCotes
{
  private:
	float threshold_;

  public:
	AdaptiveQuadrature(double (*function)(double), float interval_begin, float interval_end);
	~AdaptiveQuadrature() { }

	double Integrate();

	inline double threshold() const { return threshold_; }
	inline void set_threshold(float threshold) { threshold_ = threshold; }
};

#endif /* ADAPTIVE_QUADRATURE_INTEGRATION_H_ */
