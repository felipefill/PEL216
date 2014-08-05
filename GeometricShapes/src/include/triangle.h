/*
 * Triangle.h
 *
 *  Created on: Jul 2, 2014
 *      Author: felipefill
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <vector>
#include "shape.h"

#define kNumberOfAngles 3

class Triangle : public Shape
{
private:
	std::vector<double> sides_;
	std::vector<double> angles_;
	double height_;

	void CalcTriangle();
	void CalcSides();
	void CalcAngles();
	double ConvertRadiansToDegress(double radians) const;
	double ConvertDegreesToRadians(double degrees) const;
public:
	Triangle();

	double Height() const;

	// Override from parent
	void Print() const;
	double Area() const;
	void AddPoint(Point &p);
};

#endif /* TRIANGLE_H_ */
