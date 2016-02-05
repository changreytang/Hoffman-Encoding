#include <iostream>
#include <cstdio>

#include "MinHeap.h"
using namespace std;

int main() {
    char ch;
    freopen("test.txt","r",stdin);
    int* array = new int[27];
    // Insert characters by ASCII values into array of size 27
    while (cin >> noskipws >> ch) {
        if((int)(ch - 97) >= 0 && (int)(ch - 97) <= 25)
            array[(int)(ch - 97)]++;
        // Insert spaces at the end of the array *ASCII value not in same range
        else if((int)(ch - 97) == -65)
            array[26]++;
    }
    MinHeap h(array);
    h.print();
    
    return 0;
}