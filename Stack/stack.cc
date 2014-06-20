#include <cstddef>
#include "stack.h"

using namespace std;

Stack::StackElement::StackElement(int value, StackElement *nextElement)
{
    this->value = value;
    this->nextElement = nextElement;
}

Stack::Stack()
{
    this->size = 0;
    this->top = NULL;
}

bool Stack::isEmpty()
{
    return this->top == NULL;
}

int Stack::getTop()
{
    return this->top->value;
}

int Stack::getSize()
{
    return this->size;
}

void Stack::push(int value)
{
    StackElement *newElement = new StackElement(value, NULL);
    if (this->top) {
        newElement->nextElement = this->top;
    }

    this->top = newElement;
    this->size++;
}

int Stack::pop()
{
    int pop = (int)NULL;

    if (this->top) {
        pop = this->top->value;
        this->top = this->top->nextElement;
        this->size--;
    }

    return pop;
}
