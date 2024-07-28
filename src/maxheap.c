#include "maxheap.h"
#include "heap_internal.h"
#include <stdlib.h>

// Max Max-heap initialization
Hptr
createMax (int cap)
{
  Hptr heap = (Hptr)malloc(sizeof(struct Heap));
  heap->nodes = (HNode **)malloc(cap * sizeof(HNode*));
  heap->capacity = cap;
  heap->size = 0;
  return heap;
}

// Insert element to heap
void
insertMax (Hptr heap, HNode *node)
{
  if (heap->size == heap->cap)
  {
    
  }
}

// Remove and return maximum element (root) from heap
HNode *
extractMax (Hptr heap)
{
}

// Get maximum element w/o removal
HNode *
peekMax (Hptr heap)
{
}
