#include "Node.h"

class Tree {
	Node* root;
public:
	Tree();
	Tree(int maxdepth);
	Tree(const Tree& obj);
	void copyTree(Node *& thisRoot, Node * sourceRoot);
	~Tree();
	Tree& operator=(Tree other);

	Node* Root() { return root; };
	void freeNode(Node* node);
	void addNode(Node* node);
	int TreeDepth(Node* node);
	int calcFitness(Node* node);
	void displayNode(Node* node);
	void displayTree();

	long fitness;
private:
};