#ifndef STACK_H
#define STACK_H

template <class T_class>
class Stack
{
private:
    class StackElement {
      public:
        T_class *value;
        StackElement *nextElement;

        inline StackElement(T_class *value, StackElement *nextElement)
        {
            this->value = value;
            this->nextElement = nextElement;
        }
    };

    StackElement *top;
    int size;

public:
    inline Stack()
    {
        this->size = 0;
        this->top = NULL;
    }

    inline bool isEmpty()
    {
        return this->top == NULL;
    }

    inline T_class *getTop()
    {
        T_class *top = NULL;

        if (this->top) {
            top = this->top->value;
        }

        return top;
    }

    inline int getSize()
    {
        return this->size;
    }

    inline void push(T_class *value)
    {
        StackElement *newElement = new StackElement(value, NULL);
        if (this->top) {
            newElement->nextElement = this->top;
        }

        this->top = newElement;
        this->size++;
    }

    inline T_class *pop()
    {
        T_class *pop = NULL;

        if (this->top) {
            pop = this->top->value;
            this->top = this->top->nextElement;
            this->size--;
        }

        return pop;
    }
};

#endif // STACK_H
