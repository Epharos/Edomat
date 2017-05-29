#ifndef PARSER_H
#define PARSER_H

#include "BTree.h"
#include <string>

class Parser
{
	std::string expression;
	BTree * tree;

	public :
		Parser();
		Parser(std::string);
		~Parser();

		BTree * getTree() const;
		std::string getExpression() const;

	private :
		BTree * expression()
};

#endif