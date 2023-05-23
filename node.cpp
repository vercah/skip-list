#include "node.h"
#include <new> //std::nothrow

template<typename Data>
Node<Data>::Node(unsigned int lvl)
    : level(lvl)
{
    nexts = new Node<Data>*[level];
    for (int i = 0; i < lvl; i++){
        nexts[i] = nullptr;
    }
}

template<typename Data>
Node<Data>::Node(unsigned int lvl, Data d)
    : level(lvl), data(d)
{
    nexts = new Node<Data>*[level];
    for (int i = 0; i < lvl; i++){
        nexts[i] = nullptr;
    }
}

template<typename Data>
Node<Data>::~Node(){
    delete[] nexts;
    level = 0;
}