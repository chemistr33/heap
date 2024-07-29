#ifndef __MINHEAP_H__
#define __MINHEAP_H__
#include "heap.h"

// Min-heap initialization
Hptr createMin (int cap);

// Insert element to min-heap
void insertMin (Hptr heap, HNode *node);

// Remove and return minimum element (root) from heap
HNode *extractMin (Hptr heap);

// Get minimum element w/o removal
HNode *peekMin (Hptr heap);

#endif //__MINHEAP_H__