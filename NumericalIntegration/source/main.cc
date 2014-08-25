/*
 * main.cc
 *
 *  Created on: Aug 19, 2014
 *      Author: felipefill
 */

#include <iostream>
#include <cmath>
#include <string>
#include "../include/newton_cotes.h"

using namespace std;

double FunctionExercA(double x) {
	return pow(M_E, x);
}

double FunctionExercB(double x) {
	double result = sqrt(1 - pow(x, 2));

	if (result != result) {
		result = 0;
	}

	return result;
}

double FunctionExercC(double x) {
	return pow(M_E, -1 * pow(x, 2));
}

void Print(double (*function)(double), const char * title)
{
	NewtonCotes newton_cotes = NewtonCotes(function, 0.0f, 1.0f, 10);

	cout << "\n\n\n" << title << endl;

	newton_cotes.set_integration_type(kMidPointRule);
	cout << "MidPoint: " << newton_cotes.Integrate() << endl;

	newton_cotes.set_integration_type(kTrapezoidRule);
	cout << "Trapezoid: " << newton_cotes.Integrate() << endl;

	newton_cotes.set_integration_type(kSimpsonRule);
	cout << "Simpson: " << newton_cotes.Integrate() << endl;
}

int main(void)
{
	Print(FunctionExercA, "Exercicio A");
	Print(FunctionExercB, "Exercicio B");
	Print(FunctionExercC, "Exercicio C");

	return 0;
}


