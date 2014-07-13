#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include "point.h"

class Shape
{
private:
    std::vector<Point> points_;

public:
    Shape();

    void AddPoint(Point &p);
    void Print();

    int NumberOfSides();
    double Area();

    inline std::vector<Point> points() const { return points_; }
};

#endif // SHAPE_H
