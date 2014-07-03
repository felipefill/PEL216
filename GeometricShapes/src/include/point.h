#ifndef POINT_H
#define POINT_H

class Point
{
    double x_;
    double y_;

public:
    Point();
    Point(double x, double y);

    inline void set_x(double x) { x_ = x; }
    inline double x() const { return x_; }

    inline void set_y(double y) { y_ = y; }
    inline double y() const { return y_; }

    double operator-(Point &p);
};

#endif // POINT_H
