#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <iostream>
#include <algorithm>
using namespace std;

class BinaryNode
{
public:
	int element;
	BinaryNode *left;
	BinaryNode *right;

	BinaryNode(const int & theElement, BinaryNode *lt, BinaryNode *rt)
		: element{ theElement }, left{ lt }, right{ rt } { }

	BinaryNode(int && theElement, BinaryNode *lt, BinaryNode *rt)
		: element{ std::move(theElement) }, left{ lt }, right{ rt } { }

	BinaryNode getOnlyChild(BinaryNode *node) {
		if (node->left != nullptr) {
			return *node->left;
		}
		else if (node->right != nullptr) {
			return *node->right;
		}
		else {
			return *node;
		}
}


};

class BinarySearchTree
{
public:
	BinarySearchTree(); 
	BinarySearchTree(const BinarySearchTree & rhs); 
	BinarySearchTree(BinarySearchTree && rhs); 
	~BinarySearchTree();


	const int & findMin() const;
	const int & findMax() const;
	bool contains(const int & x) const;
	bool isEmpty() const;
	void printTree() const;
	void printTreeLevelOrder() const; // Level order
	void makeEmpty();
	void insert(const int & x);
	void insert(int && x);
	void remove(const int & x);
	int identifyBranches();

	
private:
	BinaryNode *root;

	void insert(const int & x, BinaryNode * & t);
	void insert(int && x, BinaryNode * & t);
	void remove(const int & x, BinaryNode * & t);
	BinaryNode * findMin(BinaryNode *t) const;
	BinaryNode * findMax(BinaryNode *t) const;
	
	bool contains(const int & x, BinaryNode *t) const;
	void printTreeLevelOrder(BinaryNode *t) const; // Level order
	void makeEmpty(BinaryNode * & t);
	void printTree(BinaryNode *t) const;
	BinaryNode * clone(BinaryNode *t) const;
	BinaryNode* getOnlyChild(BinaryNode *node);
	int findBranches(BinaryNode *node);

};

#endif
