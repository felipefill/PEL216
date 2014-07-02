#include "point3d.h"
#include "math.h"

Point3D::Point3D()
{
    Point();
    z_ = 0;
}

Point3D::Point3D(double x, double y, double z)
{
    Point(x, y);
    z_ = z;
}

double Point3D::operator -(Point3D *p)
{
    return Point::operator -(p) + pow(z_ - p->z(), 2.0f);
}
