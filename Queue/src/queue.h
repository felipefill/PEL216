#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue
{
private:
    class QueueElement {
      public:
        T *value;
        QueueElement *next;

        inline QueueElement(T *value, QueueElement *next)
        {
            this->value = value;
            this->next = next;
        }
    };

    QueueElement *first;
    QueueElement *last;
    int size;

public:
    inline Queue()
    {
        this->first = NULL;
        this->last = NULL;
        this->size = 0;
    }

    inline bool isEmpty() const
    {
        return this->size == 0;
    }

    inline int getSize() const
    {
        return this->size;
    }

    inline T *getTop() const
    {
        T *top = NULL;

        if (this->top) {
            top = this->top->value;
        }

        return top;
    }

    inline void queue(T *value)
    {
        QueueElement *newElement = new QueueElement(value, NULL);

        if (this->isEmpty()) {
            this->first = newElement;
        }
        else {
            this->last->next = newElement;
        }

        this->last = newElement;

        this->size++;
    }

    inline T *dequeue()
    {
        T *value = NULL;

        if (this->getSize() > 0) {
            QueueElement *first = this->first;
            value = first->value;

            if (first == this->last) {
                this->first = NULL;
                this->last = NULL;
            }
            else {
                this->first = first->next;
            }

            delete first;
            this->size--;
        }

        return value;
    }
};

#endif // QUEUE_H
