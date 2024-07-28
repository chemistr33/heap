#ifndef __HEAP_INTERNAL_H_
#define __HEAP_INTERNAL_H_

#include "../include/heap.h"

// Definition of the Heap structure, kept private
struct Heap {
  HNode **nodes;
  int cap;
  int size;
};

#endif // __HEAP_INTERNAL_H_
