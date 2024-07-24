#ifndef __MAXHEAP_H_
#define __MAXHEAP_H_

#include <stddef.h>

// DIY offsetof macro
#define _offsetof(type, member) ((size_t) & (((type *)0)->member))

// DIY containerof macro
#define _containerof(ptr, type, member)                                       \
  ({                                                                          \
    const typeof (((type *)0)->member) *__mptr = (ptr);                       \
    (type *)((char *)__mptr - _offsetof (type, member));                      \
  })

typedef struct HeapNode
{
  int key;
} HeapNode;

typedef struct Heap Heap;

// Heap Init
Heap *createHeap (int capacity);

// Insert element to heap
void insert (Heap *heap, HeapNode *node);

// Remove and return maximum element (root) from heap
HeapNode *extractMax (Heap *heap);

// Get maximum element w/o removal
HeapNode *peek (Heap *heap);

// Return size of heap
int size (Heap *heap);

// Check if heap is empty
int isEmpty(Heap *heap);

// Print heap elements
void printHeap(Heap *heap, void (*print_fptr)(HeapNode *));

// Free heap
void freeHeap(Heap *heap);

#endif //  __MAXHEAP_H_