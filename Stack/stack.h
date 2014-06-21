#ifndef STACK_H
#define STACK_H

class Stack
{
private:
    class StackElement {
      public:
        int value;
        StackElement *nextElement;

        StackElement(int value, StackElement *nextElement);
    };

    StackElement *top;
    int size;

public:
    Stack();
    bool isEmpty();
    int getTop();
    int getSize();
    void push(int value);
    int pop();
};

#endif // STACK_H
