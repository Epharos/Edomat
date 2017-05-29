#include <iostream>
#include "Parser.h"
#include "Node.h"

using namespace std;

Parser::Parser()
{
	this->tree = NULL;
	this->expression = "";
}

Parser::Parser(string s)
{
	this->tree = new BTree(new Node());
	this->expression = s;
}

Parser::~Parser()
{
	delete this->tree;
}

string Parser::getExpression()
{
	return this->expression;
}

BTree * Parser::getTree()
{
	return this->expresion();
}

/*--------------*/

BTree * Parser::expression()
{
	
}

