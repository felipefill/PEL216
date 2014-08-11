/*
 * main.cc
 *
 *  Created on: Aug 10, 2014
 *      Author: felipefill
 */


#include <iostream>
#include "include/gradient_descent.h"

using namespace std;

int main(void)
{
	std::vector<int> function;

	// x^3 - 2 * x^2 + 2
//	function.push_back(2);
//	function.push_back(0);
//	function.push_back(-2);
//	function.push_back(1);

	// x^2
	function.push_back(0);
	function.push_back(0);
	function.push_back(1);

	GradientDescent grad = GradientDescent(function, 2);

	cout << "Result: " << grad.Calculate() << endl;

	return 0;
}

