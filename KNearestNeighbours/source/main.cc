/*
 * main.cc
 *
 *  Created on: Sep 7, 2014
 *      Author: felipe
 */

#include "../include/k_nearest_neighbours.h"

#define kDatasetPath "/home/felipe/Development/FEI/PEL216/KNearestNeighbours/resources/Books_attend_grade.dat"

using namespace std;

void PrintForK(KNearestNeighbours & knn, int k)
{
	cout << "\n\n Printing for k = " << k << endl;
	cout << "Books: 0     Attends:     5    Grade Estimation: " << knn.Estimate(0, 5, k)  << endl;
	cout << "Books: 4     Attends:    20    Grade Estimation: " << knn.Estimate(4, 20, k) << endl;
	cout << "Books: 2     Attends:    10    Grade Estimation: " << knn.Estimate(2, 10, k) << endl;
	cout << "Books: 4     Attends:    15    Grade Estimation: " << knn.Estimate(4, 15, k) << endl;
}

int main(void)
{
	KNearestNeighbours knn = KNearestNeighbours(kDatasetPath);

	PrintForK(knn, 1);
	PrintForK(knn, 2);
	PrintForK(knn, 3);
	PrintForK(knn, 5);
	PrintForK(knn, 10);

	return 0;
}

/*
  Printing for k = 1
Books: 0     Attends:     5    Grade Estimation: 61
Books: 4     Attends:    20    Grade Estimation: 88
Books: 2     Attends:    10    Grade Estimation: 47
Books: 4     Attends:    15    Grade Estimation: 89


 Printing for k = 2
Books: 0     Attends:     5    Grade Estimation: 63.5
Books: 4     Attends:    20    Grade Estimation: 87.5
Books: 2     Attends:    10    Grade Estimation: 44
Books: 4     Attends:    15    Grade Estimation: 72


 Printing for k = 3
Books: 0     Attends:     5    Grade Estimation: 61
Books: 4     Attends:    20    Grade Estimation: 86
Books: 2     Attends:    10    Grade Estimation: 43.6667
Books: 4     Attends:    15    Grade Estimation: 71


 Printing for k = 5
Books: 0     Attends:     5    Grade Estimation: 58.8
Books: 4     Attends:    20    Grade Estimation: 88.8
Books: 2     Attends:    10    Grade Estimation: 47
Books: 4     Attends:    15    Grade Estimation: 73.2


 Printing for k = 10
Books: 0     Attends:     5    Grade Estimation: 54.9
Books: 4     Attends:    20    Grade Estimation: 72.9
Books: 2     Attends:    10    Grade Estimation: 51.8
Books: 4     Attends:    15    Grade Estimation: 72.5
*/
 */


