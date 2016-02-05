#include <cstdlib>
#include <iostream>
#include "MinHeap.h"
#include "Node.h"

using namespace std;


MinHeap::MinHeap() {
    heap_array = NULL;
    size = 0;
}

MinHeap::MinHeap(int* array) {
    int count = 0;
    int j = 1;
    for (int i = 0; i < 27; i++) {
        if(array[i] != 0)
            count++;
    }
    size = count + 1;
    heap_array = new Node*[size];
    for (int i = 0; i < 26; i++) {
        if(array[i] != 0 ) {
            char c = (char)(i+97);
            heap_array[j] = new Node(c, array[i]);
            j++;
        }
    }
    if (array[26] != 0) {
        char c = ' ';
        heap_array[size - 1] = new Node(c, array[26]);
    }
    heapify();
}

void MinHeap::heapify() {
    for(int i = size/2; i > 0; --i) {
          percolateDown(i);
    }
}

void MinHeap::percolateDown(int index) {
    int child_index; 
    Node* temp = heap_array[index];
    for( ; index*2 < size; index = child_index) {
        child_index = index*2;
        // Check if there is a right child that is less than or equal to value of left child
        if(child_index < (size - 1) && heap_array[child_index + 1]->getCount() <= heap_array[child_index]->getCount())
            child_index++;
        // Check if the child is actually less than the parent value
        if(heap_array[child_index]->getCount() < heap_array[index]->getCount()) {
            heap_array[index] = heap_array[child_index];
            heap_array[child_index] = temp;
        } else {
            break;
        }
    }
}

void MinHeap::insert(Node* n) {
    
}

void MinHeap::print() {
    for(int i = 1; i < size; i++ ) {
        cout << heap_array[i]->getCount() << " " << heap_array[i]->getCharacter() << endl;
    }
}

Node* MinHeap::deleteMin() {
    Node* temp = heap_array[1];
    heap_array[1] = heap_array[size - 1];
    delete heap_array[size - 1];
    --size;
    return temp;
}