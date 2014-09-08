/*
 * dataset.cc
 *
 *  Created on: Sep 7, 2014
 *      Author: felipe
 */

#include <cmath>
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

vector<int> Dataset::SortForCombination(int books, int attends)
{
	vector<double> euclidian_distance;
	vector<int> indexes;

	double distance;
	double term1;
	double term2;
	for (int i = 0; i < size(); i++) {
		term1 = pow(books - attends, 2.0f);
		term2 = pow(books_.at(i) - attends_.at(i), 2.0f);
		distance = sqrt(term1 + term2);
		euclidian_distance.push_back(distance);

		indexes.push_back(i);
	}

	for (int i = 0; i < size() -1; i++) {
		for (int j = i + 1; j < size(); j++) {
			if (euclidian_distance.at(indexes.at(i)) < euclidian_distance.at(indexes.at(j))) {
				int aux = indexes[j];
				indexes[j] = indexes[i];
				indexes[i] = aux;
			}
		}
	}

	return indexes;
}
