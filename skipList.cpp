#include "list.h"
#include "iterator.h"
#include <new> //std::nothrow

SkipList::SkipList()
	: first(new Node()), last(new Node()),
	itemCount(0)
{
	first->next = last;
	first->down = last;
}

void SkipList::print() const {
	Node *index = first->down;
}

void SkipList::clean() {
	Item *index = first->down;
	while (!isEmpty())
	{
		pop();
	}
	itemCount = 0;
}

List::~List() {
	clean();
	delete first;
	delete last;
}
