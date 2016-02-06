#ifndef ENCODE_H
#define ENCODE_H

#include <cstdlib>
#include <string>
#include "Node.h"
#include "MinHeap.h"

using namespace std;

class Encode {
private:
    Node* root;
    string* huff_codes;
    
    string returnCode(int* arr, int size);
    
public:
    Encode();
    Encode(MinHeap heap);
    
    void printLeaves(Node* root);
    Node* getRoot() { return this->root; }
    void encodeCharacters(Node* root, int* arr, int index);
    void decodeCharacters(Node* root, string code);
    void printCharacterEncoding();
    void printHuffmanCode(char c);

};

#endif