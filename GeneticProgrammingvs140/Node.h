#pragma once
// This file will hold the class declarations for
// the node sub class. This class will hold:
// * pointers
// * mathematical functions
// * constants
// * variables

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>

class Node {
	Node* left;
	Node* right;
	Node* up;
	friend class Tree;
public:
	Node();
	~Node();

	int funct;
private:
};