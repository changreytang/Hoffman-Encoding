#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <stdlib>
#include "Node.h"

class MinHeap {
private:
    Node* root;
    
    Node** heapifyArray(Node** array);
    void percolateDownArray(Node** array, int index);
    
public:
    MinHeap();
    MinHeap(int* array)

    void insert(Node value, Node* root);
    void lookupMin();
    void deleteMin();
    
};

#endif MIN_HEAP_H