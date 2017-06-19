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

		BTree * getTree();
		std::string getExpression() const;

	private :
		BTree * parseExpression(std::string);
		BTree * parseTerme(std::string);
		BTree * parseFactor(std::string);
		BTree * parseValue(std::string);
};

#endif