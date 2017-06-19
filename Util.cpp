#include <iostream>
#include "Util.h"

using namespace std;

int Util::next(string s, char c)
{
	return next(s, c, 0);
}

int Util::next(string s, char c, int j)
{
	for(int i = j ; i < s.size() ; i++)
		if(s[i] == c)
			return i;

	return -1;
}

int Util::concideringParenthesis(string s)
{
	int first = next(s, '(');
	int count = 0;

	for(int i = first ; i < s.size() ; i++)
	{
		if(s[i] == '(')
			count++;

		if(s[i] == ')')
			if(count == 1)
				return i;
			else
				count--;
	}

	return -1;
}