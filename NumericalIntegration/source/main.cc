/*
 * main.cc
 *
 *  Created on: Aug 19, 2014
 *      Author: felipefill
 */

#include <iostream>
#include "../include/newton_cotes.h"

using namespace std;

double teste(double x) {
	return x*2;
}

int main(void)
{
	NewtonCotes newton_cotes = NewtonCotes(teste, 0.0f, 1.0f, 10);

	cout << newton_cotes.Integrate() << endl;

	return 0;
}


