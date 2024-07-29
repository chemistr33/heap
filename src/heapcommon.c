#include "heap_internal.h"
#include <stdlib.h>
#include <stdio.h>

// Return size of heap
int
size (Hptr heap)
{
  return heap->size;
}

// Check if heap is empty
int
isEmpty (Hptr heap)
{
  return (heap->size == 0);
}

// Check if heap is full
int
isFull (Hptr heap)
{
  return (heap->size == heap->cap);
}

// Print heap elements
void
printHeap (Hptr heap, void (*print_fptr) (HNode *))
{
  for (int i = 0; i < heap->nodes[i]; i++)
    {
      print_fptr (heap->nodes[i]);
    }
  printf ("\n");
}

// Free heap
void
freeHeap (Hptr heap)
{
  free (heap->nodes);
  free (heap);
}
