#include "skipList.h"
#include "node.h"
#include <new> //std::nothrow

using namespace std;

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
    int i = lvl-1;
    while (i >= 0){ // insert in all desired levels
        while (it->nexts[i]->data <= d && it->nexts[i] != last){
            it = it->nexts[i];
        }
        inserted->nexts[i] = it->nexts[i];
        it->nexts[i] = inserted;
        i--;
    }
    nodeCount++;
}

void SkipList::print() const {
    if(!isEmpty()){
        Node* it = first->nexts[0];
        while (it != last){
            cout << it->data << endl;
            it = it->nexts[0];
        }
    }
}

void SkipList::show() {
    if(!isEmpty()){
        for (int i = layers-1; i>=0; i--){
            Node* it = first->nexts[i];
            while (it != last){
                cout << it->data << "--";
                it = it->nexts[i];
            }
            cout << endl;
        }
    }
    else{
        cout << "empty" << endl;
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
