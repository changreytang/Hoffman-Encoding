#ifndef NODE_H
#define NODE_H

#include <cstdlib>

class Node {
private:
    char character;
    int count;
    Node* left;
    Node* right;

public:
    Node();
    Node(char character, int count);
    Node(char character, int count, Node* left, Node* right);
    
    char getCharacter();
    int getCount();
    Node* getLeft() { return this->left; }
    Node* getRight() { return this->right; }
};

#endif