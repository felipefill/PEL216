/*
 * k_nearest_neighbours.h
 *
 *  Created on: Sep 9, 2014
 *      Author: felipefill
 */

#ifndef K_NEAREST_NEIGHBOURS_H_
#define K_NEAREST_NEIGHBOURS_H_

#include "dataset.h"

class KNearestNeighbours
{
  private:
	Dataset training_set_;

  public:
	KNearestNeighbours(const char * training_set_path);
	float Estimate(int books, int attends, int k);
};

#endif /* K_NEAREST_NEIGHBOURS_H_ */
