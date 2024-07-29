#ifndef __MAXHEAP_H__
#define __MAXHEAP_H__
#include "heap.h"

// Max-heap initialization
Hptr createMax (int cap);

// Insert element to max-heap
void insertMax (Hptr heap, HNode *node);

// Remove and return maximum element (root) from heap
HNode *extractMax (Hptr heap);

// Get maximum element w/o removal
HNode *peekMax (Hptr heap);

#endif // __MAXHEAP_H__