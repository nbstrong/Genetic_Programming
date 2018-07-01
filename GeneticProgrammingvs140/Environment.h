#pragma once
// This file will hold the class declarations for
// the environment object. The environment object
// will manage:
// * reproduction
// * testing
// * selection
// * death

#include "Tree.h"

class Environment {
public:
	Environment();
	Environment(const int maxpop, const int maxgen, const int maxtreedepth, const int mutationrate);
	~Environment();

	void evolve();
	void displayVector(std::vector<Tree>& popvec);
	void Environment::tourneyselection(std::vector<Tree>& popvec);
private:
	int Maxpop;
	int Maxgen;
	double Mutationrate;
	int Maxdepth;

};