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

	/*
	 * Although this is a template class, it only supports primitive types.
	 * If you wanna use it for other types, do it on your own risk.
	 */

	template <class T>
	class Vector
	{
	  private:
        std::vector<T> elements_;
		int capacity_;

	  public:
        Vector()
        {
            capacity_ = 0;
        }
        
		Vector(int capacity)
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
