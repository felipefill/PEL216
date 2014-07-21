/*
 * matrix.h
 *
 *  Created on: Jul 20, 2014
 *      Author: felipefill
 */

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
		Vector<T> * elements_;
		int capacity_;

	  public:
		SquareMatrix(int capacity)
		{
			capacity_ = capacity;

			int square = sqrt(capacity);
			elements_ = new Vector<T>[square];

			for (int i = 0; i < square; i++) {
				elements_[i] = Vector<T>(square);
			}
		}

		~SquareMatrix()
		{
            if (elements_)
                delete [] elements_;
		}

		Vector<T> operator[] (int index) const
		{
			return elements_[index];
		}

		Vector<T> & operator[] (int index)
		{
			return elements_[index];
		}

	};
}

#endif /* MATRIX_H_ */
