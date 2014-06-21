#include <cstddef>
#include "queue.h"

Queue::QueueElement::QueueElement(int value, QueueElement *next)
{
    this->value = value;
    this->next = next;
}

Queue::Queue()
{
    this->first = NULL;
    this->last = NULL;
    this->size = 0;
}

bool Queue::isEmpty()
{
    return this->size == 0;
}

int Queue::getSize()
{
    return this->size;
}

void Queue::queue(int value)
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

int Queue::dequeue()
{
    int value = (int)NULL;

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
