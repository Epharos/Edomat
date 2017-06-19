#include <iostream>
#include "Parser.h"
#include "Node.h"
#include "Util.h"

using namespace std;

Parser::Parser()
{
	tree = NULL;
	expression = "";
}

Parser::Parser(string s)
{
	tree = new BTree(new Node());
	expression = s;
	cout << "Parser started : " << s << endl;
}

Parser::~Parser()
{
	delete tree;
}

string Parser::getExpression() const
{
	return expression;
}

BTree * Parser::getTree()
{
	return parseExpression(getExpression());
}

/*--------------*/

BTree * Parser::parseExpression(string s)
{
	cout << "PARSING EXPRESSION" << endl;
	int plus = Util::next(s, '+');
	int minus = Util::next(s, '-');

	if(plus == -1 && minus == -1)
		return parseTerme(s);

	BTree * tree = NULL;

	if(plus != -1 && ((minus != -1 && plus < minus) || (minus == -1)))
	{
		tree = new BTree(new Node(NULL, NULL, "+"));
		tree->getStart()->setLeft(parseTerme(s.substr(0, plus))->getStart());
		tree->getStart()->setRight(parseExpression(s.substr(plus + 1))->getStart());
	}
	else if(minus != -1 && ((plus != -1 && minus < plus) || (plus == -1)))
	{
		tree = new BTree(new Node(NULL, NULL, "-"));
		tree->getStart()->setLeft(parseTerme(s.substr(0, minus))->getStart());
		tree->getStart()->setRight(parseExpression(s.substr(minus + 1))->getStart());
	}
	else
		cerr << "Error parsing expression !" << endl;

	return tree;
}

BTree * Parser::parseTerme(string s)
{
	cout << "PARSING TERM" << endl;
	int time = Util::next(s, '*');
	int divide = Util::next(s, '/');

	if(time == -1 && divide == -1)
		return parseFactor(s);

	BTree * tree = NULL;

	if(time != -1 && ((divide != -1 && time < divide) || (divide == -1)))
	{
		tree = new BTree(new Node(NULL, NULL, "*"));
		tree->getStart()->setLeft(parseFactor(s.substr(0, time))->getStart());
		tree->getStart()->setRight(parseTerme(s.substr(time + 1))->getStart());
	}
	else if(divide != -1 && ((time != -1 && divide < time) || (time == -1)))
	{
		tree = new BTree(new Node(NULL, NULL, "/"));
		tree->getStart()->setLeft(parseFactor(s.substr(0, divide))->getStart());
		tree->getStart()->setRight(parseTerme(s.substr(divide + 1))->getStart());
	}
	else
		cerr << "Error parsing expression !" << endl;

	return tree;
}

BTree * Parser::parseFactor(string s)
{
	cout << "PARSING FACTOR" << endl;

	int firstParenthesis = Util::next(s, '(');

	if(firstParenthesis == -1)
		return parseValue(s);

	return parseExpression(s.substr(1, s.size() - 2));
}

BTree * Parser::parseValue(string s)
{
	cout << "PARSING VALUE" << endl;
	return new BTree(new Node(NULL, NULL, s));
}