/*
 * main.cc
 *
 *  Created on: Aug 19, 2014
 *      Author: felipefill
 */

#include <iostream>
#include <cmath>
#include <string>
#include "mpi.h"
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
	int taskid;
	NewtonCotes newton_cotes = NewtonCotes(function, 0.0f, 1.0f, 10);

	MPI_Comm_rank(MPI_COMM_WORLD,&taskid);

	if (taskid == 0)
		cout << "\n" << title << endl;

	newton_cotes.Integrate();
}

int main(int argc, char ** argv)
{
	MPI_Init(&argc,&argv);

	Print("Exercicio A", FunctionExercA, FunctionExercANDerivative, FunctionExercANDerivative);
	Print("Exercicio B", FunctionExercB, FunctionExercBSecondDerivative, FunctionExercBFourthDerivative);
	Print("Exercicio C", FunctionExercC, FunctionExercCSecondDerivative, FunctionExercCFourthDerivative);

	MPI_Finalize();
	return 0;
}

/*
Exercicio A
There will be 2 tasks.
Each task is taking up an avearage of 5
I am task 0
Task 0: my interval begins with 0
Task 0 integrating interval 0 - 0.1
Task 0: slice 1 of 5
Task 0 integrating interval 0.1 - 0.2
Task 0: slice 2 of 5
Task 0 integrating interval 0.2 - 0.3
Task 0: slice 3 of 5
Task 0 integrating interval 0.3 - 0.4
Task 0: slice 4 of 5
Task 0 integrating interval 0.4 - 0.5
Task 0: slice 5 of 5
Task 0: my result = 0.648451

I am task 1
Task 1: my interval begins with 0.5
Task 1 integrating interval 0.5 - 0.6
Task 1: slice 1 of 5
Task 1 integrating interval 0.6 - 0.7
Task 1: slice 2 of 5
Task 1 integrating interval 0.7 - 0.8
Task 1: slice 3 of 5
Task 1 integrating interval 0.8 - 0.9
Task 1: slice 4 of 5
Task 1 integrating interval 0.9 - 1
Task 1: slice 5 of 5
Task 1: my result = 1.06912

>>>>>FINAL RESULT: 1.71757

Exercicio B
There will be 2 tasks.
Each task is taking up an avearage of 5
I am task 0
Task 0: my interval begins with 0
Task 0 integrating interval 0 - 0.1
Task 0: slice 1 of 5
Task 0 integrating interval 0.1 - 0.2
Task 0: slice 2 of 5
Task 0 integrating interval 0.2 - 0.3
Task 0: slice 3 of 5
Task 0 integrating interval 0.3 - 0.4
Task 0: slice 4 of 5
Task 0 integrating interval 0.4 - 0.5
Task 0: slice 5 of 5
Task 0: my result = 0.478546

I am task 1
Task 1: my interval begins with 0.5
Task 1 integrating interval 0.5 - 0.6
Task 1: slice 1 of 5
Task 1 integrating interval 0.6 - 0.7
Task 1: slice 2 of 5
Task 1 integrating interval 0.7 - 0.8
Task 1: slice 3 of 5
Task 1 integrating interval 0.8 - 0.9
Task 1: slice 4 of 5
Task 1 integrating interval 0.9 - 1
Task 1: slice 5 of 5
Task 1: my result = 0.309557

>>>>>FINAL RESULT: 0.788103

Exercicio C
There will be 2 tasks.
Each task is taking up an avearage of 5
I am task 0
Task 0: my interval begins with 0
Task 0 integrating interval 0 - 0.1
Task 0: slice 1 of 5
Task 0 integrating interval 0.1 - 0.2
Task 0: slice 2 of 5
Task 0 integrating interval 0.2 - 0.3
Task 0: slice 3 of 5
Task 0 integrating interval 0.3 - 0.4
Task 0: slice 4 of 5
Task 0 integrating interval 0.4 - 0.5
Task 0: slice 5 of 5
Task 0: my result = 0.461606

I am task 1
Task 1: my interval begins with 0.5
Task 1 integrating interval 0.5 - 0.6
Task 1: slice 1 of 5
Task 1 integrating interval 0.6 - 0.7
Task 1: slice 2 of 5
Task 1 integrating interval 0.7 - 0.8
Task 1: slice 3 of 5
Task 1 integrating interval 0.8 - 0.9
Task 1: slice 4 of 5
Task 1 integrating interval 0.9 - 1
Task 1: slice 5 of 5
Task 1: my result = 0.285525

>>>>>FINAL RESULT: 0.747131
*/
