#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <cstdlib>
#include "Node.h"

class MinHeap {
private:
    Node** heap_array;
    int size;
    
    void heapify();
    void percolateDown(int index);
    void percolateUp(int index);
    
public:
    MinHeap();
    MinHeap(int* array);

    void insert(Node* n);
    Node* deleteMin();
    void print();
    
};

#endif