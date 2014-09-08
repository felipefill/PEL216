/*
 * dataset_reader.h
 *
 *  Created on: Sep 7, 2014
 *      Author: felipe
 */

#ifndef DATASET_READER_H_
#define DATASET_READER_H_

#include <string>
#include "dataset.h"

class DatasetReader
{
	public:
		static Dataset read(const char * path);
};

#endif /* DATASET_READER_H_ */
