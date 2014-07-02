#include "point.h"
#include "math.h"

Point::Point()
{
    x_ = 0;
    y_ = 0;
}

Point::Point(double x, double y)
{
    x_ = x;
    y_ = y;
}

double Point::operator -(Point *p)
{
    return pow(x_ - p->x(), 2.0f) + pow(y_ - p->y(), 2.0f);
}
