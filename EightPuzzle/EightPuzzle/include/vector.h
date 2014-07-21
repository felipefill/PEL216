/*
 * vector.h
 *
 *  Created on: Jul 20, 2014
 *      Author: felipefill
 */

#ifndef VECTOR_H_
#define VECTOR_H_

namespace eightPuzzle {

	/*
	 * Although this is a template class, it only supports primitive types.
	 * If you wanna use it for other types, do it on your own risk.
	 */

	template <class T>
	class Vector
	{
	  private:
		T *elements_;
		int capacity_;

	  public:
        Vector()
        {
            elements_ = nullptr;
            capacity_ = 0;
        }
        
		Vector(int capacity)
		{
			capacity_ = capacity;
			elements_ = new T[capacity_];
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
