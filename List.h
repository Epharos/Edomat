#ifndef LIST
#define LIST

class List
{
	Element * start;

	public :
		List();
		List(Element *);
		~List();

		Element * get(int);

	private :
		Element * get(int, int);
};

#endif