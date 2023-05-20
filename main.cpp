#include <iostream>
#include "skipList.h"

using namespace std;

//TODO: funkce generující náhodná čísla, která potom seřadí pomocí skiplistu

int main()
{
	SkipList *l;
	for (int i = 0; i < 10; i++) {
		l.insert(i);
		l.insert(20 - i);
	}
//
//	l.remove(20);
//	l.print();
//	l.clean();
//	cout << "#prvku: " <<
//		l.getElementCount() << endl;
	return 0;
}
