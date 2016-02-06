#include <cstdlib>
#include <iostream>
#include "Node.h"
#include "MinHeap.h"
#include "Encode.h"

using namespace std;

Encode::Encode() {
    root = NULL;
    huff_codes = NULL;
}

Encode::Encode(MinHeap heap) {
    while(heap.getSize() > 2) {
        Node* n1 = heap.deleteMin();
        Node* n2 = heap.deleteMin();
        char c = '#';
        Node* tri_node = new Node(c, n1->getCount()+n2->getCount(), n2, n1);
        heap.insert(tri_node);
    }
    this->root = heap.getRoot();
    this->huff_codes = new string[27];
}

void Encode::printLeaves(Node* root) {
    if(root == NULL)       
        return;
    if(root->getLeft() == NULL && root->getRight() == NULL)      
        cout << root->getCount() << " " << root->getCharacter() << endl;
    printLeaves(root->getLeft()); 
    printLeaves(root->getRight());      
}