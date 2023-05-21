#ifndef NODE_H
#define NODE_H

#include "type.h"

#include <iostream>

class Node {
	Data data;
	unsigned int level;
	Node* nexts;
public:
	Node(unsigned int lvl);
	Node(unsigned int lvl, Data d);
	~Node();
	void setData(const Data d) { data = d; }
	Data getData() const { return data; }
	void print() const { std::cout << data; }
	void printLn() const {
		print();
		std::cout << std::endl;
	}
	friend class SkipList; // let SkipList access private Node pointers
};


#endif // NODE_H
