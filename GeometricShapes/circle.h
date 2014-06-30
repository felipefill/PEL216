#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"

class Circle : public Point
{
private:
    double radius_;

public:
    Circle();

    inline void set_radius(double radius) { radius_ = radius; }
    inline double radius() const { return radius_; }
};

#endif // CIRCLE_H
