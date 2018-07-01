// Genetic Programming in C++
// This file will control variables, input function,
// output data, control filestream
// Overall objective: Implement genetic programming function

// Last milestone: Trees can now freely be copied by shuffle/sort.

// Current objective: 

// Thoughts: Tourneyselection is not modifiable from source and may need to be rewritten

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>

#include "Environment.h"

int main() {
	const int targetfunction = 5;
	const int maxpop = 10;
	const int maxgen = 10;
	const int maxtreedepth = 5;
	const double mutationrate = 0.1;
	srand(time(0));

	// Create environment object
	Environment env(maxpop, maxgen, maxtreedepth, mutationrate);

	env.evolve();

	system("Pause");
	return 0;
}