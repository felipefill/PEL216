/*
 * main.cc
 *
 *  Created on: Aug 10, 2014
 *      Author: felipefill
 */

#include "include/gradient_descent.h"

int main(void)
{
	std::vector<int> function;
	function.push_back(0);
	function.push_back(0);
	function.push_back(1);

	GradientDescent grad = GradientDescent(function, 2);

	grad.calculate();

	return 0;
}

