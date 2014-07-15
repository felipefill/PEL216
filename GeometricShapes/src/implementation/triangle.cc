#include <cmath>
#include <iostream>
#include "triangle.h"
#include "points_overflow_exception.h"
#include "not_enough_points_exception.h"

using namespace std;

/********************************************************
 ******************* PUBLIC METHODS ********************
 ********************************************************/

/***
 * Default constructor
 */
Triangle::Triangle()
{
	height_ = 0;
}

/***
 * Calculates the height of the triangle
 */
double Triangle::Height() const
{
	// area = 0.5*base*height
	// We will use the first side as base
	return Area() / (0.5 * sides_.at(0));
}

/***
 * Adds a new point to the triangle composition
 */
void Triangle::AddPoint(Point &p)
{
	if (points().size() < 3) {
		Shape::AddPoint(p);
		if (points().size() == 3) {
			CalcTriangle();
		}
	}
	else {
		throw PointsOverflowException();
	}
}

/***
 * Calculates the area of the triangle
 */
double Triangle::Area() const
{
	double area = 0.0f;

	// We will use Heron's formula to calc the area of the triangle
	if (sides_.size() == 3) {
		double s = 0.0f;

		for (int i = 0; i < 3; i++) {
			s += sides_.at(i);
		}

		s /= 2;

		area = sqrt(s * (s - sides_.at(0)) * (s - sides_.at(1)) * (s - sides_.at(2)));
	}
	else {
		throw NotEnoughPointsException();
	}

	return area;
}

/***
 * Prints out information about the triangle, containing its points, measures, angles, height and area.
 */
void Triangle::Print() const
{
	if (NumberOfSides() == 3) {
		static const int CAPITAL_A_ASCII_CODE = 'A';
		static const int MINUSCULE_A_ASCII_CODE = 'a';

		cout << "-----------------------------------------------" << endl;
		cout << "I'm a triangle, I have " << NumberOfSides() << " sides!" << endl;

		cout << "\nThe points that compose me are: " << endl;
		for (int i = 0; i < points().size(); i++) {
			cout << "P" << i+1 << " = (" << points().at(i).x() << ", "<< points().at(1).y() << ")" << endl;
		}

		cout << "\nMy side's measures are:" << endl;
		for (int i = 0; i < sides_.size(); i++) {
			char measureId = MINUSCULE_A_ASCII_CODE + i;
			cout << measureId << " = " << sides_.at(i) << endl;
		}

		cout << "\nMy angles are:" << endl;
		for (int i = 0; i < angles_.size(); i++) {
			char angleId = CAPITAL_A_ASCII_CODE + i;
			cout << angleId << " = " << angles_.at(i) << endl;
		}

		cout << "I have a height of " << Height() << endl;
		cout << "Lastly, I have an area of " << Area() << endl;
	}
	else {
		throw NotEnoughPointsException();
	}
}

/********************************************************
 ******************* PRIVATE METHODS ********************
 ********************************************************/

void Triangle::CalcTriangle()
{
	CalcSides();
	CalcAngles();
}

void Triangle::CalcSides()
{
	if (sides_.size() == 0) {
		for (int i = 0; i < 3; i++) {
			int j = (i == 2 ? 0 : i + 1);
			sides_.push_back(points().at(i) - points().at(j));
		}
	}
}

void Triangle::CalcAngles()
{
	int largestAngleIndex = 0;

	if (sides_.at(1) > sides_.at(largestAngleIndex)) {
		largestAngleIndex = 1;
	}

	if (sides_.at(2) > sides_.at(largestAngleIndex)) {
		largestAngleIndex = 2;
	}

	double dividend = -1 * pow(sides_.at(largestAngleIndex), 2.0f);
	double divisor = 2.0f;
	std::vector<int> remainingAnglesIndex;
	for (int i = 0; i < 3; i++)  {
		if (i != largestAngleIndex) {
			dividend += pow(sides_.at(i), 2.0f);
			divisor *= sides_.at(i);
			remainingAnglesIndex.push_back(i);
		}
	}

	double acosLargestAngle = acos(dividend / divisor);
	angles_[largestAngleIndex] = ConvertRadiansToDegress(acosLargestAngle);

	dividend = sides_.at(remainingAnglesIndex.at(0)) * sin(ConvertDegreesToRadians(angles_[largestAngleIndex]));
	divisor = sides_.at(largestAngleIndex);

	double ordinaryAsinOfNonLargestAngle = asin(dividend / divisor);
	angles_[remainingAnglesIndex.at(0)] = ConvertRadiansToDegress(ordinaryAsinOfNonLargestAngle);

	angles_[remainingAnglesIndex.at(1)] = 180.0f;
	for (int i = 0; i < 3; i++) {
		if (i != remainingAnglesIndex.at(1)) {
			angles_[remainingAnglesIndex.at(1)] -= angles_[i];
		}
	}
}

double Triangle::ConvertRadiansToDegress(double radians) const
{
	return radians * (180.0f / M_PI);
}

double Triangle::ConvertDegreesToRadians(double radians) const
{
	return radians * (M_PI / 180.0f);
}




