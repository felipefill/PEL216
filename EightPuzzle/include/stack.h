//
//  stack.h
//  EightPuzzle
//
//  Created by Felipe Fill Cardoso on 7/21/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#ifndef STACK_PUZZLE_H
#define STACK_PUZZLE_H

namespace eightPuzzle {

template <class T>
class Stack
{
private:
    class StackElement {
      private:
        T * value_;
        StackElement * next_element_;
        
      public:
        inline StackElement(T * value, StackElement * next_element)
        {
            value_ = value;
            next_element_ = next_element;
        }
        
        inline T * value() const { return value_; }
        inline void set_value(T * value) { value_ = value; }
        
        inline StackElement * next_element() const { return next_element_; }
        inline void set_next_element(StackElement * next_element) { next_element_ = next_element; }
    };

    StackElement * top_;
    int size_;

public:
    inline Stack()
    {
        size_ = 0;
        top_ = nullptr;
    }

    inline bool IsEmpty() const
    {
        return top_ == NULL;
    }

    inline T * top() const
    {
        T *top = nullptr;

        if (top_) {
            top = top_->value();
        }

        return top;
    }

    inline int size() const
    {
        return size_;
    }

    inline void Push(T * value)
    {
        StackElement *new_element = new StackElement(value, nullptr);

        if (top_) {
            new_element->set_next_element(top_);
        }

        top_ = new_element;
        size_++;
    }

    inline T * Pop()
    {
        T * pop = nullptr;

        if (top_) {
            StackElement * popped_element = top_;
            pop = popped_element->value();

            top_ = popped_element->next_element();

            delete popped_element;
            size_--;
        }

        return pop;
    }
};

}

#endif // STACK_PUZZLE_H
