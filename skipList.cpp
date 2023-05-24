#include "skipList.h"
#include "node.h"
#include <new> //std::nothrow

using namespace std;

template<typename Data>
SkipList<Data>::SkipList(unsigned int lrs)
	: nodeCount(0), layers(lrs)
{
    first = new Node<Data>(lrs);
    last = new Node<Data>(lrs);
	for (int i = 0; i<lrs; i++){
	    first->nexts[i] = last;
	}
}

template<typename Data>
SkipList<Data>::~SkipList() {
	clean();

	delete first;
	delete last;
}

template<typename Data>
Node<Data>* SkipList<Data>::find(Data d){
    if (isEmpty()){
        return nullptr;
    }
    int i = layers - 1;
    Node<Data>* it = first;
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

template<typename Data>
void SkipList<Data>::insert(Data d){
    unsigned int lvl = (rand() % layers)+1; // number of levels to be included in
    Node<Data>* inserted = new Node<Data>(lvl, d);
    Node<Data>* it = first;
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

template<typename Data>
void SkipList<Data>::print() const {
    if(!isEmpty()){
        Node<Data>* it = first->nexts[0];
        while (it != last){
            cout << it->data << endl;
            it = it->nexts[0];
        }
    }
}

template<typename Data>
void SkipList<Data>::show() {
    if(!isEmpty()){
        for (int i = layers-1; i>=0; i--){
            Node<Data>* it = first->nexts[i];
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

template<typename Data>
Node<Data>* SkipList<Data>::findBefore(Node<Data>* node, unsigned int layer){
    if (isEmpty()){
        return nullptr;
    }
    Node<Data>* before = first;
    while (before->nexts[layer] != node && before->nexts[layer] != last){
        before = before->nexts[layer];
    }
    return before->nexts[layer] == last ? nullptr : before;
}

template<typename Data>
bool SkipList<Data>::remove(Data d){
    Node<Data>* found = find(d);
    Node<Data>* foundBefore;
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

template<typename Data>
void SkipList<Data>::clean() {
	while (!isEmpty())
	{
		pop();
	}
	nodeCount = 0;
}

template<typename Data>
Data SkipList<Data>::pop() {
	Data it = first->nexts[0]->data;
	remove(first->nexts[0]->data);
	return it;
}
