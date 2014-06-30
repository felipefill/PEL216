#ifndef POINT_H
#define POINT_H

class Point
{
    float x_;
    float y_;

public:
    Point(float x, float y);
    ~Point();

    inline void set_x(float x) { x_ = x; }
    inline float x() const { return x_; }

    inline void set_y(float y) { y_ = y; }
    inline float y() const { return y_; }
};

#endif // POINT_H
