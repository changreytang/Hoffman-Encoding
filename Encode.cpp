#include <cstdlib>
#include "Node.h"
#include "MinHeap.h"
#include "Encode.h"

Encode::Encode() {
    
}

Encode::Encode(MinHeap heap) {
    this->heap = heap;
}