#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
private:
    class QueueElement {
      public:
        int value;
        QueueElement *next;

        QueueElement(int value, QueueElement *next);
    };

    QueueElement *first;
    QueueElement *last;
    int size;

public:
    Queue();

    bool isEmpty();
    int getSize();
    void queue(int value);
    int dequeue(void);
};

#endif // QUEUE_H
