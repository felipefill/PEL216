#include <iostream>
#include "circle.h"
#include "shape.h"

using namespace std;

int main()
{
    cout << "Hello World!\n\n" << endl;

    Circle myShape = Circle(100.0f);
    myShape.print();

    return 0;
}

