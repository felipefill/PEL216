/*
 * Triangle.h
 *
 *  Created on: Jul 2, 2014
 *      Author: felipefill
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <array>
#include "shape.h"

class Triangle : public Shape
{
private:
	std::vector<double> sides_;
	std::array<double, 3> angles_;
	double height_;

	void calcTriangle();
	void calcSides();
	void calcAngles();
	double convertRadiansToDegress(double radians);
	double convertDegreesToRadians(double degrees);
public:
	Triangle();

	double height();

	// Override from parent
	void print();
	double area();
	void addPoint(Point &p);
};

#endif /* TRIANGLE_H_ */
