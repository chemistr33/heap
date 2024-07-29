#include "maxheap.h"
#include "heap_internal.h"
#include <stdlib.h>

// Max-heap initialization
Hptr
createMax (int cap)
{
  Hptr heap = (Hptr)malloc (sizeof (struct Heap));
  heap->nodes = (HNode **)malloc (cap * sizeof (HNode *));
  heap->cap = cap;
  heap->size = 0;
  return heap;
}

// Insert element to max-heap
void
insertMax (Hptr heap, HNode *node)
{
  // Check if the heap is full
  if (isFull (heap))
    {
      perror ("Heap Full.");
      return;
    }

  // Insert new node at end of heap
  heap->nodes[heap->size] = node;
  int index = heap->size;
  heap->size++;
  
  // Re-heapify the heap (heapify-up) from now terminal new node
  while (index > 0)
    {
      int parentIndex = (index - 1) / 2;

      // Check if new node key > parent key
      if (heap->nodes[index]->key <= heap->nodes[parentIndex]->key)
        {
          break; // return from function 
        }

      // Swap new node with parent
      HNode *temp = heap->nodes[index];
      heap->nodes[index] = heap->nodes[parentIndex];
      heap->nodes[parentIndex] = temp;

      // Move to the parent's index
      index = parentIndex;
    }
}

// Remove and return maximum element (root) from heap
HNode *
extractMax (Hptr heap)
{
  // Check if heap is empty
  if (isEmpty (heap))
    {
      perror ("Heap Empty.");
      return NULL;
    }

  // Save maximum node (root)
  HNode *maxNode = heap->nodes[0];

  // Move terminal node in heap up to root position
  heap->nodes[0] = heap->nodes[heap->size - 1];

  // Decrement heap size
  heap->size--;

  // Re-heapify (down from now root new node)
  int index = 0;
  while (index < heap->size)
    {
      int lchild = 2 * index + 1;
      int rchild = 2 * index + 2;
      int largest = index;

      // Find largest value between current node and left child
      if (lchild < heap->size
          && heap->nodes[lchild]->key > heap->nodes[largest]->key)
        {
          largest = lchild;
        }

      // Find largest value between current node and right child
      if (rchild < heap->size
          && heap->nodes[rchild]->key > heap->nodes[largest]->key)
        {
          largest = rchild;
        }

      // If largest == current, heap is properly ordered so break out
      if (largest == index)
        break;

      // Swap current node with largest child
      HNode *temp = heap->nodes[index];
      heap->nodes[index] = heap->nodes[largest];
      heap->nodes[largest] = temp;

      // Move to the largest child's index
      index = largest;
    }

  return maxNode;
}

// Get maximum element w/o removal
HNode *
peekMax (Hptr heap)
{
  if (isEmpty (heap))
    return NULL;
  return heap->nodes[0];
}
