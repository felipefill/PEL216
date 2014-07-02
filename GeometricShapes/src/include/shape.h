#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include "point.h"

class Shape
{
private:
    std::vector<Point> points_;

public:
    virtual void print() = 0;
    virtual double area() = 0;

    int numberOfSides();

    inline void set_points(std::vector<Point> points) { points_ = points; }
    inline std::vector<Point> points() const { return points_; }
};

#endif // SHAPE_H
