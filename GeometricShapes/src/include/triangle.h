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

#define kNumberOfAngles 3

class Triangle : public Shape
{
private:
	std::vector<double> sides_;
	std::array<double, kNumberOfAngles> angles_;
	double height_;

	void CalcTriangle();
	void CalcSides();
	void CalcAngles();
	double ConvertRadiansToDegress(double radians);
	double ConvertDegreesToRadians(double degrees);
public:
	Triangle();

	double Height();

	// Override from parent
	void Print();
	double Area();
	void AddPoint(Point &p);
};

#endif /* TRIANGLE_H_ */
