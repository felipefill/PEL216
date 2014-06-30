#ifndef SHAPE_H
#define SHAPE_H

#include <array>
#include "point.h"

class Shape
{
private

    std::array points_;

public:
    Shape(std::array points);
    virtual area() = 0;

    int numberOfSides();
    inline std::array points() const { return points_; }
};

#endif // SHAPE_H
