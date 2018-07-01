
#include "Environment.h"

#ifndef Environment_H
#define Environemnt_H

Environment::Environment() {
	std::cout << "> constructing Environment object" << std::endl;
}

Environment::Environment(const int maxpop, const int maxgen, const int maxdepth, const int mutationrate) {
	std::cout << "> constructing Environment object with overload" << std::endl;
	Maxpop = maxpop;
	Maxgen = maxgen;
	Maxdepth = maxdepth;
	Mutationrate = mutationrate;
	Tree* bestfitness = NULL;
}

Environment::~Environment() {
	std::cout << "> destructing Environment object" << std::endl;

}

// Main evolution function, this is where the magic happens
void Environment::evolve() {
	std::vector<Tree> popvec;

	// Initial population
	while (popvec.size() < Maxpop) {
		Tree membertree(Maxdepth);
		popvec.push_back(membertree);
	}

	// Subsequent Generations
	for (int i = 1;i <= Maxgen; i++) {
		std::cout << "Generation " << i << std::endl;

		// Select and kill
		tourneyselection(popvec);

		// Repopulate
		while (popvec.size() < Maxpop) {
			Tree membertree(Maxdepth);
			popvec.push_back(membertree);
		}
		displayVector(popvec);

		// i is counter for filling vector, j and k 
		for (int i = Maxpop - popvec.size(), int j = 0, int k = 1; i < Maxpop; i++, j++, k++) {
			if (i >= Maxpop - (popvec.size * Mutationrate)) {
				mutateTree(popvec[i]);
			}
			else {
				crossTree(popvec[i].Root());
			}
		}
	}

	std::sort(popvec.begin(), popvec.end(), [](const Tree& obj1, const Tree& obj2) {return obj1.fitness > obj2.fitness; });
	std::cout << "Best Fitness: " << popvec[0].fitness << std::endl;
	popvec[0].displayTree();
}

// Shuffles array, compares two elements and deletes lower one.
void Environment::tourneyselection(std::vector<Tree>& popvec) {
	std:random_shuffle(popvec.begin(), popvec.end());
	for (int i = 0, j = 1; j <= popvec.size()-1; i += 2, j += 2) {
		if (popvec[i].fitness < popvec[j].fitness) {
			popvec[i].fitness = NULL;
		}
		else {
			popvec[j].fitness = NULL;
		}
	}
	for (int k = 0; k <= popvec.size() - 1;) {
		if (popvec[k].fitness == NULL) {
			popvec.erase(popvec.begin() + k);
		}
		else {
			k++;
		}
	}
}

void Environment::displayVector(std::vector<Tree>& popvec) {

	// Prints vector
	for (int i = 0; i < popvec.size(); i++) {
		std::cout << popvec[i].fitness << " ";
	} std::cout << std::endl; // keep this inline

	// Prints distribution of single digits
	/*int distr[10] = { 0 };
	for (int i = 0; i < popvec.size() - 1; i++) {
	distr[popvec[i].fitness] += 1;
	}
	for (int i = 0; i < 10; i++) {
	std::cout << i << ":" << distr[i] << " ";
	} std::cout << std::endl;*/

	// Prints average of fitness
	/*double sum = 0;
	for (int i = 0; i <= popvec.size()-1; i++) {
	sum = sum + popvec[i].fitness;
	}
	std::cout << std::fixed;
	std::cout << std::setprecision(2) << "Avg: " << sum / popvec.size()  << std::endl;*/

	// Prints highest fitness
	/*long best = 0;
	for (int i = 0; i < popvec.size() - 1; i++) {
		if (popvec[i].fitness > best) {
			best = popvec[i].fitness;
		}
	}
	std::cout << "Best: " << best << std::endl;*/

}




#endif