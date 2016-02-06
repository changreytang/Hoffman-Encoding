#ifndef ENCODE_H
#define ENCODE_H

#include <cstdlib>
#include <string>
#include "Node.h"
#include "MinHeap.h"

class Encode {
private:
    Node* root;
    string* huff_codes;
    string current_code = "";
    
    void encodeCharacters(Node* root);
    
public:
    Encode();
    Encode(MinHeap heap);
    
    void printLeaves(Node* root);
    Node* getRoot() { return this->root; }

};

#endif