#ifndef POINT3D_H
#define POINT3D_H

class Point3D : public Point
{
private:
    float z_;

public:
    Point3D(float x, float y, float z);
    ~Point3D();

    inline void set_z(float z) { z_ = z; }
    inline float z() const { return z_; }
};

#endif // POINT3D_H
