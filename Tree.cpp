#include <iostream>
#include "BTree.h"
#include "Node.h"

using namespace std;

BTree::BTree()
{
	this->start = NULL;
}

BTree::BTree(Node * s)
{
	this->start = s;
}

BTree::~BTree()
{
	if(this->start != NULL)
		delete this->start;
}

Node * BTree::getStart() const
{
	return this->start;
}

void BTree::setStart(Node * n)
{
	this->start = n;
}

/* ----------------- */

Node::Node()
{
	this->left = NULL;
	this->right = NULL;
	this->content = "";
}

Node::Node(Node * l, Node * r, string c)
{
	this->left = l;
	this->right = r;
	this->content = c;
}

Node::~Node()
{
	if(this->left != NULL)
		delete this->left;

	if(this->right != NULL)
		delete this->right;
}

Node * Node::getLeft() const
{
	return this->left;
}

Node * Node::getRight() const
{
	return this->right;
}

string Node::getContent() const
{
	return this->content;
}

void Node::setLeft(Node * n)
{
	this->left = n;
}

void Node::setRight(Node * n)
{
	this->right = n;
}

void Node::setLeft(BTree * n)
{
	this->setLeft(n->getStart());
}

void Node::setRight(BTree * n)
{
	this->setRight(n->getStart());
}

void Node::setContent(string s)
{
	this->content = s;
}