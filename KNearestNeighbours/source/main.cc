/*
 * main.cc
 *
 *  Created on: Sep 7, 2014
 *      Author: felipe
 */

#include "../include/dataset_reader.h"

#define kDatasetPath "/home/felipe/Development/FEI/PEL216/KNearestNeighbours/resources/Books_attend_grade.dat"
#define N 5

using namespace std;

int main(void)
{
	Dataset data = DatasetReader::read(kDatasetPath);

	data.SortForCombination(0, 1);

	return 0;
}


