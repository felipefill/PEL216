#include <iostream>
#include "shape.h"
#include "not_implemented_yet_exception.h"

using namespace std;

Shape::Shape()
{
}

void Shape::AddPoint(Point& p)
{
	points_.push_back(p);
}

void Shape::Print()
{
	throw NotImplementedException();
}

int Shape::NumberOfSides()
{
    int number_of_points = points().size();
    int number_of_sides;

    if (number_of_points < 2) {
        number_of_sides = number_of_points - 1;
    }
    else {
        number_of_sides = number_of_points;
    }

    return number_of_sides;
}

double Shape::Area()
{
	throw NotImplementedException();
}
