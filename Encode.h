#ifndef ENCODE_H
#define ENCODE_H

#include <cstdlib>
#include "Node.h"
#include "MinHeap.h"

class Encode {
private:
    MinHeap heap;
    Node* root;
    
public:
    Encode();
    Encode(MinHeap heap);

};

#endif