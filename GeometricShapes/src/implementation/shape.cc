#include "shape.h"

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
