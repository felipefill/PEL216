#include <cmath>
#include <iostream>
#include "../include/circle.h"
#include "../include/points_overflow_exception.h"
#include "../include/not_enough_points_exception.h"

using namespace std;

Circle::Circle(double radius)
{
	Point point = Point(0,0);
	AddPoint(point);

	radius_ = radius;
}

void Circle::AddPoint(Point &p)
{
	if (points().size() == 0) {
		Shape::AddPoint(p);
	}
	else {
		throw PointsOverflowException();
	}
}

double Circle::Area() const
{
	return M_PI * pow(radius(), 2.0f);
}

void Circle::Print() const
{
	cout << "I'm a circle, I have " << NumberOfSides() << " sides!" << endl;
	cout << "I have " << points().size() << " point and a radius of " << radius() << endl;
	cout << "Lastly, I have an area of " << Area() << endl;
}
