/*
 * KNearestNeighbours.cc
 *
 *  Created on: Sep 9, 2014
 *      Author: felipefill
 */

#include <cmath>
#include "../include/k_nearest_neighbours.h"
#include "../include/dataset_reader.h"

KNearestNeighbours::KNearestNeighbours(const char * training_set_path)
{
	training_set_ = DatasetReader::read(training_set_path);
}

float KNearestNeighbours::Estimate(int books, int attends, int k)
{
	vector<int> sorted_indexes = SortForCombination(books, attends);

	int iterations = sorted_indexes.size() > k ? k : sorted_indexes.size();

	int sum = 0;
	for (int i = 0; i < iterations; i++) {
		sum += training_set_.grade(sorted_indexes.at(i));
	}

	return  (float)sum / (float)iterations;
}

vector<int> KNearestNeighbours::SortForCombination(int books, int attends)
{
	vector<double> euclidian_distance;
	vector<int> indexes;

	double distance;
	double term1;
	double term2;
	for (int i = 0; i < training_set_.size(); i++) {
		term1 = pow(books - training_set_.books(i), 2.0f);
		term2 = pow(attends - training_set_.attends(i), 2.0f);
		distance = sqrt(term1 + term2);
		euclidian_distance.push_back(distance);

		indexes.push_back(i);
	}

	for (int i = 0; i < training_set_.size() -1; i++) {
		for (int j = i + 1; j < training_set_.size(); j++) {
			if (euclidian_distance.at(indexes.at(i)) > euclidian_distance.at(indexes.at(j))) {
				int aux = indexes[j];
				indexes[j] = indexes[i];
				indexes[i] = aux;
			}
		}
	}

	return indexes;
}

