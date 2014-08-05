//
//  vector.h
//  EightPuzzle
//
//  Created by Felipe Fill Cardoso on 7/21/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#ifndef VECTOR_H_
#define VECTOR_H_

#include <vector>

namespace eightPuzzle {

	template <class T>
	class Line
	{
	  private:
        std::vector<T> elements_;
		int capacity_;

	  public:
        Line()
        {
            capacity_ = 0;
        }
        
		Line(int capacity)
		{
			capacity_ = capacity;
            elements_.reserve(capacity);
		}

		T operator[] (int index) const
		{
			return elements_[index];
		}

		T & operator[] (int index)
		{
			return elements_[index];
		}

	};

}

#endif /* VECTOR_H_ */
