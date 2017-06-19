#ifndef NODE
#define NODE

#include <string>

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
		void setContent(std::string);
};

#endif