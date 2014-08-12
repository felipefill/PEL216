/*
 * main.cc
 *
 *  Created on: Aug 10, 2014
 *      Author: felipefill
 */


#include <iostream>
#include "include/gradient_descent.h"

using namespace std;

void PrintResultWithStep(GradientDescent grad, double step, double initial, double final)
{
	for (double i = initial; i < final + 0.001f; i = i+step)
	{
		cout << "Step(" << i << ") = " << grad.Calculate(0.0f, i, 1000) << endl;
	}
}

int main(void)
{
	// x^2
	std::vector<int> exerc_a;
	exerc_a.push_back(0);
	exerc_a.push_back(0);
	exerc_a.push_back(1);

	// x^3 - 2 * x^2 + 2
	std::vector<int>exerc_b;
	exerc_b.push_back(2);
	exerc_b.push_back(0);
	exerc_b.push_back(-2);
	exerc_b.push_back(1);

	cout << "Results for Exercise A: " << endl;
	PrintResultWithStep(GradientDescent(exerc_a, 2), 0.1f, 0.1f, 1.0f);

	cout << "\nResults for Exercise B: " << endl;
	PrintResultWithStep(GradientDescent(exerc_b, 2), 0.1f, 0.1f, 1.0f);

	return 0;
}

