#include <cmath>
#include <iostream>
#include "circle.h"

using namespace std;

Circle::Circle(double radius)
{
	Point point = Point(0,0);
	addPoint(point);

	radius_ = radius;
}

void Circle::addPoint(Point &p)
{
	if (points().size() == 0) {
		Shape::addPoint(p);
	}
}

double Circle::area()
{
	return M_PI * pow(radius(), 2.0f);
}

void Circle::print()
{
	cout << "I'm a circle, I have " << numberOfSides() << " sides!" << endl;
	cout << "I have " << points().size() << " points and a radius of " << radius() << endl;
	cout << "Lastly, I have an area of " << area() << endl;
}
