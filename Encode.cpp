#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
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

void Encode::encodeCharacters(Node* root, int* arr, int index) {
    if(root == NULL)       
        return;
    if(root->getLeft()) {
        arr[index] = 1;
        encodeCharacters(root->getLeft(), arr, index + 1);
    }
    if(root->getRight()) {
        arr[index] = 0;
        encodeCharacters(root->getRight(), arr, index + 1);
    }
    if(root->getLeft() == NULL && root->getRight() == NULL) {
        int ind = (int)(root->getCharacter() - 97);
        if(ind < 0)
            huff_codes[26] = returnCode(arr, index);
        else {
            huff_codes[ind] = returnCode(arr, index); 
        }
        return;
    }
}

void Encode::decodeCharacters(Node* root, string code) {
    if(root == NULL)
        return;
    if(root->getLeft() == NULL && root->getRight() == NULL) {
        cout << root->getCharacter();
        decodeCharacters(this->root, code);
    }
    if(code[0] == '1') {
        decodeCharacters(root->getLeft(), code.substr(1, code.length() - 1));
    }
    if(code[0] == '0') {
        decodeCharacters(root->getRight(), code.substr(1, code.length() - 1));
    }
}

string Encode::returnCode(int* arr, int size) {
    string final = "";
    for(int i = 0; i < size; i++) {
        final += to_string(arr[i]);
    }
    return final;
}

void Encode::printLeaves(Node* root) {
    if(root == NULL)       
        return;
    if(root->getLeft() == NULL && root->getRight() == NULL)      
        cout << root->getCount() << " " << root->getCharacter() << endl;
    printLeaves(root->getLeft()); 
    printLeaves(root->getRight());      
}

void Encode::printCharacterEncoding() {
    for(int i = 0; i < 27; i++) {
        if(huff_codes[i] != "") {
            char c;
            if(i == 26)
                c = ' ';
            else {
                c = (char) (i + 97);
            }
            cout << c << ": " << huff_codes[i] << endl;
        }
    }
}

void Encode::printHuffmanCode(char c) {
    if(c == ' ')
        cout << huff_codes[26];
    else
        cout << huff_codes[(int)(c - 97)];
}