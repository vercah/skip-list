#include "node.h"
#include <new> //std::nothrow

Node::Node(unsigned int lvl)
    : level(lvl)
{
    nexts = new Node*[level];
    for (int i = 0; i < lvl; i++){
        nexts[i] = nullptr;
    }
}

Node::Node(unsigned int lvl, Data d)
    : level(lvl), data(d)
{
    nexts = new Node*[level];
    for (int i = 0; i < lvl; i++){
        nexts[i] = nullptr;
    }
}

Node::~Node(){
    delete[] nexts;
    level = 0;
}