/*
 * dataset.h
 *
 *  Created on: Sep 7, 2014
 *      Author: felipe
 */

#ifndef DATASET_H_
#define DATASET_H_

#include <iostream>
#include <vector>

using namespace std;

class Dataset
{
  private:
	vector<int> books_;
	vector<int> attends_;
	vector<int> grade_;
	int size_;

  public:
	Dataset();

	inline int books(int index) const { return books_.at(index); }
	inline int attends(int index) const { return attends_.at(index); }
	inline int grade(int index) const { return grade_.at(index); }

	inline int size() const { return size_; }

	void AddLine(int books, int attends, int grade);
};

#endif /* DATASET_H_ */
