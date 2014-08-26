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

double FunctionExercANDerivative(double x) {
	return pow(M_E, x);
}

double FunctionExercB(double x) {
	double result = sqrt(1 - pow(x, 2));

	if (result != result) {
		result = 0;
	}

	return result;
}

double FunctionExercBSecondDerivative(double x) {
	///-(1 - x^2)^(-3/2)
	double first = 1 - pow(x,2);
	first *= -1;

	double second = 3/2;
	second *= -1;

	return pow(first, second);
}

double FunctionExercBFourthDerivative(double x) {
	///-((3 + 12 x^2)/(1 - x^2)^(7/2))
	double up = 3 + 12 * pow(x, 2);
	up *= -1;

	double down = pow(1 - pow(x, 2), 7/2);

	return up/down;
}

double FunctionExercC(double x) {
	return pow(M_E, -1 * pow(x, 2));
}

double FunctionExercCSecondDerivative(double x) {
	//(-2 + 4 x^2)/E^x^2
	double up = -2 + 4 * pow(x, 2);
	double down = pow(M_E, pow(x, 2));

	return up/down;
}

double FunctionExercCFourthDerivative(double x) {
	//(4 (3 - 12 x^2 + 4 x^4))/E^x^2
	double up = 4 * (3 - 12 * pow(x, 2) + 4 * pow(x, 4));
	double down = pow(M_E, pow(x, 2));

	return up/down;
}

void Print(const char * title, double (*function)(double), double (*second_derivative)(double), double (*fourth_derivative)(double))
{
	NewtonCotes newton_cotes = NewtonCotes(function, 0.0f, 1.0f, 10);

	cout << "\n\n\n" << title << endl;

	newton_cotes.set_integration_type(kMidPointRule);
	cout << "MidPoint: " << newton_cotes.Integrate() << endl;
	cout << "Error: " << newton_cotes.ErrorWithDerivative(second_derivative) << endl;

	newton_cotes.set_integration_type(kTrapezoidRule);
	cout << "\nTrapezoid: " << newton_cotes.Integrate() << endl;
	cout << "Error: " << newton_cotes.ErrorWithDerivative(second_derivative) << endl;

	newton_cotes.set_integration_type(kSimpsonRule);
	cout << "\nSimpson: " << newton_cotes.Integrate() << endl;
	cout << "Error: " << newton_cotes.ErrorWithDerivative(fourth_derivative) << endl;
}

int main(void)
{
	Print("Exercicio A", FunctionExercA, FunctionExercANDerivative, FunctionExercANDerivative);
	Print("Exercicio B", FunctionExercB, FunctionExercBSecondDerivative, FunctionExercBFourthDerivative);
	Print("Exercicio C", FunctionExercB, FunctionExercCSecondDerivative, FunctionExercCFourthDerivative);

	return 0;
}


