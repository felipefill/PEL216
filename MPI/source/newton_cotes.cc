/*
 * newton_cotes.cc
 *
 *  Created on: Aug 19, 2014
 *      Author: felipefill
 */

#include <cmath>
#include <iostream>
#include <exception>
#include "mpi.h"
#include "../include/newton_cotes.h"

#define MASTER 0

using namespace std;

NewtonCotes::NewtonCotes(double (*function)(double), float interval_begin, float interval_end, int slicing)
	: NumericalIntegrationBase(function, interval_begin, interval_end, slicing)
{
}

double NewtonCotes::IntegrateInterval(float begin, float end)
{
	return (end - begin) * function((begin + end) / 2.0f);
}

void NewtonCotes::Integrate()
{
	int numtasks, taskid;
	double result = 0.0f;
	int slice = 0;

	MPI_Comm_size(MPI_COMM_WORLD,&numtasks);
	MPI_Comm_rank(MPI_COMM_WORLD,&taskid);

	int tasks_per_id = slicing() / numtasks;

	float previous_step = interval_begin() + (taskid * step_size());
	double myresult = 0.0f;
	for (float current_step = interval_begin() + step_size(); slice < tasks_per_id; current_step += step_size(), slice++) {
		myresult += IntegrateInterval(previous_step, current_step);
		previous_step = current_step;
	}

	int rc = MPI_Reduce(&myresult, &result, 1, MPI_DOUBLE, MPI_SUM,
                   MASTER, MPI_COMM_WORLD);
	 
	if (rc != MPI_SUCCESS)
		printf("%d: failure on mpc_reduce\n", taskid);

	if (taskid == MASTER)
		cout << "Result: " << result << endl;
}

double NewtonCotes::ErrorWithDerivative(double(*derivative)(double))
{
	double result = 0.0f;
	int slice = 0;

	float previous_step = interval_begin();
	for (float current_step = interval_begin() + step_size(); slice < slicing(); current_step += step_size(), slice++) {
		result += (pow(current_step - previous_step, 3.0f) / 24.0f) * derivative(interval_begin());
	}

	return result;
}
