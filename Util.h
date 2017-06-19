#ifndef UTIL
#define UTIL

#include <string>
#include "List.h"

class Util
{
	static int * starts;
	static int * ends;

	public :
		static int next(std::string, char);
		static int next(std::string, char, int);
		static int concideringParenthesis(std::string);
		static void setStartsAndEnds(std::string);
};

#endif