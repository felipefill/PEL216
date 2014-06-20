#include <iostream>
#include "stack.h"

using namespace std;

void testStack();

int main()
{
    testStack();
    return 0;
}

void testStack()
{
    Stack *stack = new Stack();

    cout << "Hello, I've just instantiated my stack!" << endl;
    cout << "This is its current size:" << stack->getSize() << endl;
    if (stack->getSize() != 0) {
        cout << "ERROR: This shouldn't be the size of the stack as it SHOULD have 0 (zero) elements." << endl;
        delete stack;
        return;
    }

    cout << "Now I'll push one element into the stack." << endl;
    cout << "Pushing element 10 into the stack..." << endl;

    stack->push(10);
    cout << "My top element now is " << stack->getTop() << " and the size is" << stack->getSize() << endl;

    if (stack->getSize() != 1) {
        cout << "ERROR: Stack size should be 1 (one)." << endl;
        delete stack;
        return;
    }

    if (stack->getTop() != 10) {
        cout << "ERROR: Stack top should be 10 (ten)." << endl;
        delete stack;
        return;
    }

    cout << "Ok, now let's push another element, the value 5 this time." << endl;
    cout << "Pushing element 5 into the stack..." << endl;

    stack->push(5);
    cout << "My top element now is " << stack->getTop() << " and the size is" << stack->getSize() << endl;

    if (stack->getSize() != 2) {
        cout << "ERROR: Stack size should be 2 (two)." << endl;
        delete stack;
        return;
    }

    if (stack->getTop() != 5) {
        cout << "ERROR: Stack top should be 5 (five)." << endl;
        delete stack;
        return;
    }

    cout << "Lastly, let's pop values from the stack!" << endl;

    int firstPop = stack->pop();
    cout << "The first pop was " << firstPop << " and the stack size now is " << stack->getSize() << endl;

    if (firstPop != 5) {
        cout << "ERROR: First pop should be 5 (five)." << endl;
        delete stack;
        return;
    }

    if (stack->getSize() != 1) {
        cout << "ERROR: Stack size should be 1 (one)." << endl;
        delete stack;
        return;
    }

    if (stack->getTop() != 10) {
        cout << "ERROR: Stack top should be 10 (ten)." << endl;
        delete stack;
        return;
    }


    int secondPop = stack->pop();
    cout << "The second pop was " << secondPop << " and the stack size now is " << stack->getSize() << endl;

    if (secondPop != 10) {
        cout << "ERROR: Second pop should be 10 (ten)." << endl;
        delete stack;
        return;
    }

    if (stack->getSize() != 0) {
        cout << "ERROR: Stack size should be 0 (zero)." << endl;
        delete stack;
        return;
    }

    if (stack->getTop() != (int)NULL) {
        cout << "ERROR: Stack top should be NULL" << endl;
        delete stack;
        return;
    }

    cout << "SUCCESS: Everything is working as expected!" << endl;
    delete stack;
}
