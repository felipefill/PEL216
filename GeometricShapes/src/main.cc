#include <iostream>
#include "include/circle.h"
#include "include/triangle.h"
#include "include/shape.h"

using namespace std;

int main()
{
    cout << "Hello World!\n\n" << endl;

    Circle myShape = Circle(100.0f);
    myShape.Print();

    cout << "\n\n";

    Triangle tri = Triangle();

    Point p;

    p = Point(-2, -2);
    tri.AddPoint(p);

    p = Point(3, -1);
    tri.AddPoint(p);

    p = Point(1, 3);
    tri.AddPoint(p);

    tri.Print();

    return 0;
}

