#ifndef NODE_H
#define NODE_H

//#include "type.h"

#include <iostream>
template<typename Data = int>

class Node {
	Data data;
	unsigned int level;
	Node<Data>** nexts;
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
	template<typename X> friend class SkipList; // let SkipList access private Node pointers
};


#endif // NODE_H
