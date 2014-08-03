//
//  square_matrix.h
//  EightPuzzle
//
//  Created by Felipe Fill Cardoso on 7/21/14.
//  Copyright (c) 2014 Felipe Fill. All rights reserved.
//

#ifndef MATRIX_H_
#define MATRIX_H_

#include "vector.h"
#include <cmath>

namespace eightPuzzle
{
    /*
        This was tested only for int, long, float and double types.
        Use it at your own risk.
     */

	template <class T>
	class SquareMatrix
	{
	  private:
        std::vector<Vector<T>> elements_;
		int capacity_;
        int square_capacity_;

	  public:
		SquareMatrix(int capacity)
		{
			capacity_ = capacity;

            square_capacity_ = sqrt(capacity);
			elements_.reserve(square_capacity());

			for (int i = 0; i < square_capacity(); i++) {
				elements_.push_back(Vector<T>(square_capacity()));
			}
		}

//		~SquareMatrix()
//		{
//            if (elements_ != nullptr) {
//                delete[] elements_;
//                elements_ = nullptr;
//            }
//		}

		Vector<T> operator[] (int index) const
		{
			return elements_[index];
		}

		Vector<T> & operator[] (int index)
		{
			return elements_[index];
		}
        
        int capacity()
        {
            return capacity_;
        }
        
        int square_capacity()
        {
            return square_capacity_;
        }

	};
}

#endif /* MATRIX_H_ */
