/*
 * KNearestNeighbours.cc
 *
 *  Created on: Sep 9, 2014
 *      Author: felipefill
 */

#include "../include/k_nearest_neighbours.h"
#include "../include/dataset_reader.h"

KNearestNeighbours::KNearestNeighbours(const char * training_set_path)
{
	training_set_ = DatasetReader::read(training_set_path);
}

float KNearestNeighbours::Estimate(int books, int attends, int k)
{
	cout << "Sorting indexes" << endl;
	vector<int> sorted_indexes = training_set_.SortForCombination(books, attends);

	cout << "Calculating number of iterations" << endl;
	int iterations = sorted_indexes.size() > k ? k : sorted_indexes.size();

	cout << "Sum" << endl;
	int sum = 0;
	for (int i = 0; i < iterations; i++) {
		sum += training_set_.grade(sorted_indexes.at(i));
	}

	cout << "returning estimation" << endl;
	return  sum / iterations;
}

