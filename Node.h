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
    char getCharacter();
    int getCount();
};

#endif