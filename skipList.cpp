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
    int i = layers - 1;
    Node* it = first;
    while (it == first || it->data != d) {
        if (it->nexts[i] == last || it->nexts[i]->data > d){
            if (i <= 0){ // if we are in the bottom layer
                return nullptr;
            }
            i--;
        }else {
            it = it->nexts[i];
        }
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

Node* SkipList::findBefore(Node* node, unsigned int layer){
    if (isEmpty()){
        return nullptr;
    }
    Node* before = first;
    while (before->nexts[layer] != node && before->nexts[layer] != last){
        before = before->nexts[layer];
    }
    return before->nexts[layer] == last ? nullptr : before;
}

bool SkipList::remove(Data d){
    Node* found = find(d);
    Node* foundBefore;
    if (!found){
        return false;
    }
    for (int i = found->level-1; i>=0; i--){
        foundBefore = findBefore(found, i);
        if(foundBefore){
            foundBefore->nexts[i] = found->nexts[i];
        }else{
            return false;
        }
    }
    delete found;
    nodeCount--;
    return true;
}

void SkipList::clean() {
	while (!isEmpty())
	{
		pop();
	}
	nodeCount = 0;
}

Data SkipList::pop() {
	Data it = first->nexts[0]->data;
	remove(first->nexts[0]->data);
	nodeCount--;
	return it;
}
