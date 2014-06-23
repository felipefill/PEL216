#include <iostream>
#include <cstdlib>
#include <ctime>
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
    Stack<int> *stack = new Stack<int>();
    int values[10];

    srand(time(NULL));

    cout << "stack->isEmpty: " << stack->isEmpty() << endl;
    cout << "stack->getSize: " << stack->getSize() << endl;

    for (int i = 0; i < 10; i++) {
        values[i] = rand() % 100 + 1;
        cout << "Adding to stack: " << values[i] << endl;
        stack->push(&values[i]);
    }

    cout << "stack->isEmpty: " << stack->isEmpty() << endl;
    cout << "stack->getSize: " << stack->getSize() << endl;

    for (int i = 9; i >= 0; i--) {
        int *popped = stack->pop();
        if (*popped != values[i]) {
            cout << "ERROR: Error while removing value from the stack.\n";
            cout << "Expected: " << values[i] << "\nActual: " << popped << endl;
            delete stack;
            return;
        }
        else {
            cout << "Removing from stack: " << values [i] << endl;
        }
    }

    cout << "stack->isEmpty: " << stack->isEmpty() << endl;
    cout << "stack->getSize: " << stack->getSize() << endl;

    delete stack;
}
