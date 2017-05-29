#ifndef BINARY_TREE
#define BINARY_TREE

#include "Node.h"

class BTree
{
	Node * start;

	public :
		BTree();
		BTree(Node *);
		~BTree();

		Node * getStart() const;
		void setStart(Node *);
};

#endif