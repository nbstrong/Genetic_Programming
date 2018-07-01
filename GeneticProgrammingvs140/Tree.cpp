#include "Tree.h"

#ifndef Tree_H
#define Tree_H

// Constructor
Tree::Tree() {
	root = NULL;
	fitness = rand() % 100; // 10 = range 0-9, 100 = range 0-99
}

// Overload constructor
Tree::Tree(int maxdepth) {
	root = NULL;
	while (TreeDepth(root) <= maxdepth) {
		addNode(root);
	}
	fitness = calcFitness(root);
}

// Copy constructor
Tree::Tree(const Tree& obj) {
	fitness = obj.fitness;
	if (obj.root == NULL) {
		root = NULL;
	}
	else {
		copyTree(this->root, obj.root);
	}
}

// Assignment Operator
Tree& Tree::operator=(Tree other) {
	if (root) {
		freeNode(root);
	}
	fitness = other.fitness;
	root = other.root;
	other.root = nullptr;

	return *this;
}

// Support for copy constructor
void Tree::copyTree(Node *& thisRoot, Node * sourceRoot) {
	if (sourceRoot == NULL)
	{
		thisRoot = NULL;
	}
	else
	{
		thisRoot = new Node;
		thisRoot->funct = sourceRoot->funct;
		thisRoot->left = sourceRoot->left;
		thisRoot->right = sourceRoot->right;
		thisRoot->up = sourceRoot->up;
		copyTree(thisRoot->left, sourceRoot->left);
		copyTree(thisRoot->right, sourceRoot->right);
	}
}

// Destructor
Tree::~Tree() {
	freeNode(root);
	root = NULL;
}

// Post traversal node deletion
void Tree::freeNode(Node* node) {
	if (node != NULL) {
		freeNode(node->left);
		freeNode(node->right);
		delete node;
	}
}

// Adds a node to the tree
void Tree::addNode(Node* node) {
	if (root == NULL) {
		Node* temp = new Node();
		root = temp;
	}
	else if (node->left == NULL) {
		Node* temp = new Node();
		node->left = temp;
	}
	else if (node->right == NULL) {
		Node* temp = new Node();
		node->right = temp;
	}
	else if (node->left != NULL) {
		addNode(node->left);
	}
	else if (node->right != NULL) {
		addNode(node->right);
	}
}

int Tree::TreeDepth(Node* node) {
	if (node == NULL) {
		return 0;
	}
	int nLeft = TreeDepth(node->left);
	int nRight = TreeDepth(node->right);
	return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
	return nRight + 1;
}

int Tree::calcFitness(Node* node) {
	if (node == NULL) {
		return 0;
	}
	int sleft = calcFitness(node->left);
	int sright = calcFitness(node->right);
	return node->funct + sleft + sright;
}

void Tree::displayNode(Node* node) {
	if (node != NULL) {
		displayNode(node->left);
		std::cout << node->funct << std::endl;
		displayNode(node->right);
	}
}

void Tree::displayTree() {
	displayNode(root);
}

// Crossover the tree
#endif