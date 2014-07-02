#ifndef POINT3D_H
#define POINT3D_H

#include "point.h"

class Point3D : public Point
{
private:
    double z_;

public:
    Point3D();
    Point3D(double x, double y, double z);

    inline void set_z(double z) { z_ = z; }
    inline double z() const { return z_; }

    double operator-(Point3D *p);
};

#endif // POINT3D_H
