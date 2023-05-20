#ifndef SKIPLIST_H
#define SKIPLIST_H

#include "type.h"
#include "node.h"

class Skiplist {
	Node *first;
	Node *last;
	unsigned int nodeCount;
	unsigned int layers;
public:
	SkipList();
	~SkipList();
	unsigned int getElementCount() const {
		return nodeCount;
	}
	bool isEmpty() const {
		return nodeCount == 0;
	}
	void clean();
	bool insert(Data d);
    Node* find(Data d);
    bool remove(Data d);
    void pop(); // used for sorting
	void print() const;
};

#endif // SKIPLIST_H