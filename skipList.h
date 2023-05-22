#ifndef SKIPLIST_H
#define SKIPLIST_H

#include "type.h"
#include "node.h"

class SkipList {
	Node *first;
	Node *last;
	unsigned int nodeCount;
	unsigned int layers;
	Node* findBefore(Node* node, unsigned int layer); // returns preceding node in the given layer
public:
	SkipList(unsigned int lrs);
	~SkipList();
	unsigned int getElementCount() const {
		return nodeCount;
	}
	bool isEmpty() const {
		return nodeCount == 0;
	}
	void clean();
	void insert(Data d);
    Node* find(Data d);
    bool remove(Data d);
    Data pop(); // used for sorting
	void print() const;
	void show();
};

#endif // SKIPLIST_H