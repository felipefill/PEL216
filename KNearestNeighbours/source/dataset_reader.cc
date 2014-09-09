/*
 * dataset_header.cc
 *
 *  Created on: Sep 7, 2014
 *      Author: felipe
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/dataset_reader.h"

using namespace std;

Dataset DatasetReader::read(const char * path)
{
	Dataset data = Dataset();

	std::ifstream inputFile(path);
	std::string line;

	while(getline(inputFile, line)) {
	  if (!line.length() || line[0] == '#')
		 continue;

	  int books, attends, grade;
	  std::istringstream iss(line);
	  iss >> books >> attends >> grade;
	  data.AddLine(books, attends, grade);
	}

	return data;
}
