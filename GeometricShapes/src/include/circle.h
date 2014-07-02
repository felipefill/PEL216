#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape
{
private:
    double radius_;

public:
    Circle(double radius);

    void print();
    double area();

    inline void set_radius(double radius) { radius_ = radius; }
    inline double radius() const { return radius_; }
};

#endif // CIRCLE_H
