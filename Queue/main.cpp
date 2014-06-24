#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"

using namespace std;

void testQueue();

int main()
{
    testQueue();
    return 0;
}

void testQueue()
{
    Queue<int> *queue = new Queue<int>();
    int values[10];

    srand(time(NULL));

    cout << "queue->isEmpty: " << queue->isEmpty() << endl;
    cout << "queue->getSize: " << queue->getSize() << endl;

    for (int i = 0; i < 10; i++) {
        values[i] = rand() % 100 + 1;
        cout << "Adding to queue: " << values[i] << endl;
        queue->queue(&values[i]);
    }

    cout << "queue->isEmpty: " << queue->isEmpty() << endl;
    cout << "queue->getSize: " << queue->getSize() << endl;

    for (int i = 0; i < 10; i++) {
         int dequeued = *queue->dequeue();
         if (dequeued != values[i]) {
            cout << "ERROR: Error while removing the " << i+1 << " value from the queue.\n";
            cout << "Expected: " << values[i] << "\nActual: " << dequeued << endl;
         }
         else {
             cout << "Removing from queue: " << values [i] << endl;
         }
    }

    cout << "queue->isEmpty: " << queue->isEmpty() << endl;
    cout << "queue->getSize: " << queue->getSize() << endl;

    delete queue;
}

