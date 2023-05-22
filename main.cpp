#include <iostream>
#include "skipList.h"

using namespace std;

void printRow(int* array, unsigned int n){
    for (int i = 0; i< n; i++){
        cout << array[i] << ", ";
    }
    cout << endl;
}

void skipSort(int* array, unsigned int n){
    cout << "We have " << n << " randomly generated integers to sort:" << endl;
    printRow(array, n);
    cout << endl;
    SkipList* l = new SkipList(10);
    for (int i = 0; i < n; i++) {
        l->insert(array[i]);
    }
    // l->show(); // to print the structure in terminal
    for (int i = 0; i < n; i++) {
        array[i] = l->pop();
    }
    cout << "--- sorted by skipSort ---" << endl;
    printRow(array, n);
}

int main()
{
    unsigned int n = 20;
    int* array = new int[n];
    for (int i = 0; i< n; i++){
        array[i] = (rand() % n)+1;
    }
    skipSort(array, n);

	return 0;
}
