#ifndef STACK_H
#define STACK_H

template <class T>
class Stack
{
private:
    class StackElement {
      public:
        T *value;
        StackElement *nextElement;

        inline StackElement(T *value, StackElement *nextElement)
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

    inline bool isEmpty() const
    {
        return this->top == NULL;
    }

    inline T *getTop() const
    {
        T *top = NULL;

        if (this->top) {
            top = this->top->value;
        }

        return top;
    }

    inline int getSize() const
    {
        return this->size;
    }

    inline void push(T *value)
    {
        StackElement *newElement = new StackElement(value, NULL);
        if (this->top) {
            newElement->nextElement = this->top;
        }

        this->top = newElement;
        this->size++;
    }

    inline T *pop()
    {
        T *pop = NULL;

        if (this->top) {
            StackElement *poppedElement = this->top;
            pop = poppedElement->value;

            this->top = poppedElement->nextElement;

            delete poppedElement;
            this->size--;
        }

        return pop;
    }
};

#endif // STACK_H
