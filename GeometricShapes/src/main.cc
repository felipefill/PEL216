#include <iostream>
#include "circle.h"
#include "triangle.h"
#include "shape.h"

using namespace std;

int main()
{
    cout << "Hello World!\n\n" << endl;

    Circle myShape = Circle(100.0f);
    myShape.print();

    cout << "\n\n";

    Triangle tri = Triangle();

    Point p;

    p = Point(-2, -2);
    tri.addPoint(p);

    p = Point(3, -1);
    tri.addPoint(p);

    p = Point(1, 3);
    tri.addPoint(p);

    tri.print();

    return 0;
}

