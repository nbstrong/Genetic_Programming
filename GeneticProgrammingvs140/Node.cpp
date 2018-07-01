#include "Node.h"

#ifndef Node_H
#define Node_H

Node::Node() {
	left = NULL;
	right = NULL;
	up = NULL;
	funct = rand() % 10; // 10 = range 0-9, 100 = range 0-99
}

Node::~Node() {
}

#endif