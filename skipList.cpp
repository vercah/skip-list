#include "skipList.h"
#include "node.h"
#include <new> //std::nothrow

SkipList::SkipList(unsigned int lrs)
	: nodeCount(0), layers(lrs)
{
    first = new Node(lrs);
    last = new Node(lrs);
	for (int i = 0; i<lrs; i++){
	    first->nexts[i] = last;
	}
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
    int i = layers - 1;
    while (it->data != d){
        if (it->nexts[i]->data > d || it->nexts[i] == last){
            if (i <= 0){ // if we are in the bottom layer
                return nullptr;
            }
            i--;
        }
        it = it->nexts[i];
    }
    return it;
}

void SkipList::insert(Data d){
    unsigned int lvl = (rand() % layers)+1; // number of levels to be included in
    Node* inserted = new Node(lvl, d);
    Node* it = first;
    int i = 0;
    while (it->nexts[0]->data <= d && it->nexts[0] != last){ // find right spot for insertion
        it = it->nexts[0];
    }
    while (i < lvl){ // insert in all desired levels
        inserted->nexts[i] = it->nexts[i];
        it->nexts[i] = inserted;
        i++;
    }
    nodeCount++;
}

void SkipList::print() const {
    if(!isEmpty()){
        Node* it = first->nexts[0];
        while (it != last){
            std::cout << it->data << std::endl;
            it = it->nexts[0];
        }
    }
}

void SkipList::show() {
    if(!isEmpty()){
        for (int i = layers-1; i>=0; i--){
            Node* it = first;
            while (it->nexts[i] != last){
                std::cout << it->nexts[i]->data << "--";
                it = it->nexts[i];
            }
            std::cout << std::endl;
        }
    }
    else{
        std::cout << "empty" << std::endl;
    }
}

void SkipList::clean() {
	Node *index = first->nexts[0];
	while (!isEmpty())
	{
		pop();
	}
	nodeCount = 0;
}

Data SkipList::pop() {
    return 0;
}
