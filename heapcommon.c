#include "heap.h"

// Internal library definition of Heap data structure
struct Heap 
{
  Heap **nodes;
  int cap;
  int size;
};

// Return size of heap
int
size (Hptr heap)
{
}

// Check if heap is empty
int
isEmpty (Hptr heap)
{
}

// Print heap elements
void
printHeap (Hptr heap, void (*print_fptr) (HNode *))
{
}

// Free heap
void
freeHeap (Hptr heap)
{
}
