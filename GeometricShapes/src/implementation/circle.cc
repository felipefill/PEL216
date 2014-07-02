#include <cmath>
#include <iostream>
#include "circle.h"

using namespace std;

Circle::Circle(double radius)
{
	// By default we will use a single point at (0,0)
	vector<Point> points;
	points.push_back(Point(0, 0));

	set_points(points);
	radius_ = radius;
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
