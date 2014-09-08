/*
 * main.cc
 *
 *  Created on: Sep 7, 2014
 *      Author: felipe
 */

#include "../include/k_nearest_neighbours.h"

#define kDatasetPath "/home/felipe/Development/FEI/PEL216/KNearestNeighbours/resources/Books_attend_grade.dat"
#define kK 5

using namespace std;

int main(void)
{
	KNearestNeighbours knn = KNearestNeighbours(kDatasetPath);

	cout << knn.Estimate(0, 5, kK) << endl;

	return 0;
}


