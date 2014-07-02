#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape
{
private:
    double radius_;

public:
    Circle(double radius);

    inline void set_radius(double radius) { radius_ = radius; }
    inline double radius() const { return radius_; }

    // Override from parent
	void print();
	double area();
	void addPoint(Point &p);
};

#endif // CIRCLE_H
