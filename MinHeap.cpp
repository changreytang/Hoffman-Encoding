#include <stdlib>
#include "Node.h"


MinHeap::MinHeap() {
    root = NULL;
}

MinHeap::MinHeap(int* array) {
    int count;
    for (int i=0; i < 27; i++) {
        if(array[i] != 0)
            count++;
    }
    Node** heap_array = new Node[count];
    for (int i=0; i < 26; i++) {
        int j = 0;
        if(array[i] != 0 ) {
            char c = (char)(i+97)
            heap_array[j] = new Node(c, array[i]);
            j++;
        }
    }
    heap_array = heapifyArray(heap_array, j + 1);
    
}

Node** MinHeap::heapifyArray(Node** array, int size) {
    
}

void MinHeap::percolateDownArray(Node** array, int index, int size) {
    int child_index; 
    Node* temp = array[index];
    for( ;index*2 <= size; index = child_index) {
        child_index = index*2
        if(child_index != size && array[child_index + 1].getCount() < array[child_index].getCount())
            child_index = child+1;
        if(array[child_index] < array[index]) {
            array[index] = array[child_count]
            array[child_count] = temp;
        } else
            break;
     }
}

void MinHeap::insert(Node value, Node* root) {
    if (root == NULL)
        root = value;
    if (Node == root) {
        
    }
    
}

void MinHeap::lookupMin() {
    
}

void MinHeap::deleteMin() {
    
}