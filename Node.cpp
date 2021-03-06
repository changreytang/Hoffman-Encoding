#include <cstdlib>
#include "Node.h"

Node::Node() {
    this->character = 0;
    this->count = 0;
    this->left = NULL;
    this->right = NULL;
}

Node::Node(char character, int count) {
    this->character = character;
    this->count = count;
    this->left = NULL;
    this->right = NULL;
}

Node::Node(char character, int count, Node* left, Node* right) {
    this->character = character;
    this->count = count;
    this->left = left;
    this->right = right;
}

char Node::getCharacter() {
    return this->character;
}

int Node::getCount() {
    return this->count;
}