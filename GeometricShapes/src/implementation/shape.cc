#include <iostream>
#include "shape.h"

using namespace std;

Shape::Shape()
{
}

void Shape::addPoint(Point& p)
{
	points_.push_back(p);
}

void Shape::print()
{
	//TODO: should throw an exception
	cout << "Not implemented yet!" << endl;
}

int Shape::numberOfSides()
{
    int numberOfPoints = points().size();
    int numberOfSides;

    if (numberOfPoints < 2) {
        numberOfSides = numberOfPoints - 1;
    }
    else {
        numberOfSides = numberOfPoints;
    }

    return numberOfSides;
}

double Shape::area()
{
	//TODO: should throw an exception
	return 0.0f;
}
