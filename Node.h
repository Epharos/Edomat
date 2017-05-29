#ifndef NODE
#define NODE

#include <string>
#include "BTree.h"

class Node
{
	Node * left;
	Node * right;

	std::string content;

	public :
		Node();
		Node(Node *, Node *, std::string);
		~Node();

		Node * getLeft() const;
		Node * getRight() const;
		std::string getContent() const;
		void setLeft(Node *);
		void setRight(Node *);
		void setLeft(BTree *);
		void setRight(BTree *);
		void setContent(std::string);
};

#endif