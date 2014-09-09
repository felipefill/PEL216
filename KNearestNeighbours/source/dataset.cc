/*
 * dataset.cc
 *
 *  Created on: Sep 7, 2014
 *      Author: felipe
 */

#include "../include/dataset.h"

Dataset::Dataset()
{
	size_ = 0;
}

void Dataset::AddLine(int books, int attends, int grade)
{
	books_.push_back(books);
	attends_.push_back(attends);
	grade_.push_back(grade);

	size_++;
}
