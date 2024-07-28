#ifndef __HEAP_H_
#define __HEAP_H_

#include <stddef.h>

// DIY offsetof macro
#define _offsetof(type, member) ((size_t) & (((type *)0)->member))

// DIY containerof macro
#define _containerof(ptr, type, member)                                       \
  ({                                                                          \
    const typeof (((type *)0)->member) *__mptr = (ptr);                       \
    (type *)((char *)__mptr - _offsetof (type, member));                      \
  })

// Fully-defined node structure, user-facing, they embed it into their structs
typedef struct HNode
{
  int key;
} HNode;

// Forward declaration of node structure, *incomplete type*
typedef struct Heap Heap;

// Heap pointer typedef
typedef Heap *Hptr;

// Return size of heap
int size (Hptr heap);

// Check if heap is empty
int isEmpty (Hptr heap);

// Print heap elements
void printHeap (Hptr heap, void (*print_fptr) (HNode *));

// Free heap
void freeHeap (Hptr heap);

#endif //  __HEAP_H_