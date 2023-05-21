#include "skipList.h"
#include "node.h"
#include <new> //std::nothrow

SkipList::SkipList()
	: nodeCount(0), layers(0)
{
    first = new Node();
    last = new Node();
	first->next = last;
	first->down = last;
}

SkipList::~SkipList() {
	clean();
	delete first;
	delete last;
}
Node* SkipList::find(Data d){
    if (isEmpty()){
        return nullptr;
    }
    Node* it = first;
    while (it->next != last && it->next->data < d){
        it = it->next;
    }
    it = it->down;
    while (it->next != last && it->data != d){
        it = it->next;
    }
    return it->data == d ? it : nullptr;
}

bool SkipList::insert(Data d){
    unsigned int depth = (rand() % 2)+1;
    Node* inserted = new Node(d);
    Node* it = first;
    if (depth == 2){
        while (it->next != last && it->next->data <= d){
            it = it->next;
        }
        inserted->next = it->next;
        it->next = inserted;
    }
    Node* preceding = find(d)

}

void SkipList::print() const {
	Node *index = first->down;
}

void SkipList::clean() {
	Node *index = first->down;
	while (!isEmpty())
	{
		pop();
	}
	nodeCount = 0;
}
