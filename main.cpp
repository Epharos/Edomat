#include <iostream>
#include "Parser.h"

using namespace std;

int main()
{
	cout << "Salut" << endl;

	Parser p("(2)+(3)");
	BTree * tree = p.getTree();
	tree->printTree();
	
	return 0;
}