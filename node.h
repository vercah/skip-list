#ifndef NODE_H
#define NODE_H

#include "type.h"

#include <iostream>

class Node {
	Data data;
	Node *next;
	Node *down;
public:
	Node() : next(nullptr), down(nullptr) {}
	Node(Data d) : data(d), next(nullptr), down(nullptr) {}
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
