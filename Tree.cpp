#include <iostream>
#include "BTree.h"
#include "Node.h"

using namespace std;

BTree::BTree()
{
	start = NULL;
}

BTree::BTree(Node * s)
{
	start = s;
}

BTree::~BTree()
{
	if(start != NULL)
		delete start;
}

Node * BTree::getStart() const
{
	return start;
}

void BTree::setStart(Node * n)
{
	start = n;
}

void BTree::printTree()
{
	printTree(getStart());
}

void BTree::printTree(Node * n)
{
	cout << "[";
	if(n->getLeft() != NULL)
		printTree(n->getLeft());
	cout << " " << n->getContent() << " ";
	if(n->getRight() != NULL)
		printTree(n->getRight());
	cout << "]";
}

/* ----------------- */

Node::Node()
{
	left = NULL;
	right = NULL;
	content = "";
}

Node::Node(Node * l, Node * r, string c)
{
	left = l;
	right = r;
	content = c;
}

Node::~Node()
{
	if(left != NULL)
		delete left;

	if(right != NULL)
		delete right;
}

Node * Node::getLeft() const
{
	return left;
}

Node * Node::getRight() const
{
	return right;
}

string Node::getContent() const
{
	return content;
}

void Node::setLeft(Node * n)
{
	left = n;
}

void Node::setRight(Node * n)
{
	right = n;
}

void Node::setContent(string s)
{
	content = s;
}