#include <iostream>
#include "skipList.h"

using namespace std;

//TODO: funkce generující náhodná čísla, která potom seřadí pomocí skiplistu

int main()
{
	SkipList* l = new SkipList(10);
	cout << "dělá to vůbec něco?" << endl;
	l->insert(5);
	for (int i = 0; i < 20; i++) {
	    unsigned int number = (rand() % 7)+1;
		l->insert(number);
	}
	//l->print();
	l->show();

//
//	l.remove(20);
//	l.print();
//	l.clean();
//	cout << "#prvku: " <<
//		l.getElementCount() << endl;
	return 0;
}
