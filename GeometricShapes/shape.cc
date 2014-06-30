#include "shape.h"

Shape::Shape(std::array points)
{
    points_ = points;
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
