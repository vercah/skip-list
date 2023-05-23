#include <iostream>
#include <chrono>
#include "skipList.h"

using namespace std;

void printRow(int* array, unsigned int n){
    for (int i = 0; i< n; i++){
        cout << array[i] << ", ";
    }
    cout << endl;
}

void skipSort(int* array, unsigned int n){
    //cout << "We have " << n << " randomly generated integers to sort:" << endl;
    //printRow(array, n);
    //cout << endl;
    SkipList* l = new SkipList(10);
    for (int i = 0; i < n; i++) {
        l->insert(array[i]);
    }
    // l->show(); // to print the structure in terminal
    for (int i = 0; i < n; i++) {
        array[i] = l->pop();
    }
    //cout << "--- sorted by skipSort ---" << endl;
    //printRow(array, n);
}

bool binarySearch(int* sorted, unsigned int n, int desired){
    int left = 0;
    int right = n-1;
    int central = (n-1)/2;
    while (left!=right){
        if (sorted[central] == desired){
            return true;
        }
        if (sorted[central] < desired){
            if (left == central){ // avoid infinite loop
                return false;
            }
            left = central;
        }else{
            right = central;
        }
        central = left + (right-left)/2;
    }
    return false;
}

void measureBinary(int* array, int arrayLength, int* desired, int desiredLength){
    skipSort(array, arrayLength); // get array sorted
    auto begin = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < desiredLength; i++){
        if (!binarySearch(array, arrayLength, desired[i])){
            //cout << desired[i] << " not found" << endl;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << desiredLength << " ints in " << arrayLength << " took binary " << elapsed.count() * 1e-9 << " seconds" << endl;
}

void measureSkipSort(unsigned int layers, int* array, int arrayLength, int* desired, int desiredLength){
    SkipList* l = new SkipList(layers);
    for (int i = 0; i < arrayLength; i++) { // create skipList
        l->insert(array[i]);
    }
    auto begin = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < desiredLength; i++){
        if (!(l->find(desired[i]))){
            //cout << desired[i] << " not found" << endl;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << desiredLength << " ints in " << arrayLength << " took skip with " << layers << " layers " << elapsed.count() * 1e-9 << " seconds" << endl;
}

int main()
{
    unsigned int n = 10000; // 80000 to generate, insert and sort by skiplist takes ~30 s on my computer
    int* array = new int[n];
    for (int i = 0; i < n; i++){
        array[i] = (rand() % n)+1;
    }

    unsigned int m = 1000; // number of ints to be found
    int* desired = new int[m];
    for (int i = 0; i < m; i++){
        desired[i] = (rand() % n)+1;
    }

    measureBinary(array, n, desired, m);
    measureSkipSort(30, array, n, desired, m);

    //skipSort(array, n);
    //cout << binarySearch(array, n, 5) << endl;


	return 0;
}
