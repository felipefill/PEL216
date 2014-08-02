#ifndef QUEUE_PUZZLE_H
#define QUEUE_PUZZLE_H

namespace eightPuzzle {

template <class T>
class Queue
{
private:
    class QueueElement {
      public:
        T *value_;
        QueueElement *next_;

        inline QueueElement(T *value, QueueElement *next)
        {
            value_ = value;
            next_ = next;
        }
        
        inline T * value() const { return value_; }
        inline void set_value(T * value) { value_ = value; }
        
        inline QueueElement * next() const { return next_; }
        inline void set_next(QueueElement * next) { next_ = next; }
    };

    QueueElement *first_;
    QueueElement *last_;
    int size_;

public:
    inline Queue()
    {
        first_ = nullptr;
        last_ = nullptr;
        size_ = 0;
    }

    inline bool IsEmpty() const
    {
        return size_ == 0;
    }

    inline int size() const
    {
        return size_;
    }

    inline void QueueItem(T * item)
    {
        QueueElement *new_element = new QueueElement(item, nullptr);

        if (IsEmpty()) {
            first_ = new_element;
        }
        else {
            last_->set_next(new_element);
        }

        last_ = new_element;

        size_++;
    }

    inline T * DequeueItem()
    {
        T * value = nullptr;

        if (size() > 0) {
            QueueElement * first = first_;
            value = first->value();

            if (first == last_) {
                first_ = nullptr;
                last_ = nullptr;
            }
            else {
                first_ = first->next();
            }

            delete first;
            size_--;
        }

        return value;
    }
};

}
#endif // QUEUE_H
