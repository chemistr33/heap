#include "minheap.h"
#include "heap_internal.h"
#include <stdlib.h>

// Max Min-heap initialization
Hptr
createMin (int cap)
{
  Hptr heap = (Hptr)malloc (sizeof (struct Heap));
  heap->nodes = (HNode **)malloc (cap * sizeof (HNode *));
  heap->cap = cap;
  heap->size = 0;
  return heap;
}

// Insert element to min-heap
void
insertMin (Hptr heap, HNode *node)
{
  if (isFull (heap))
    {
      perror ("Heap Full.");
      return;
    }

  // Insert new node at end of heap, set loop variable size, and increment size
  heap->nodes[heap->size] = node;
  int index = heap->size;
  heap->size++;

  // Re-heapify the heap (heapify-up) from now terminal new node
  while (index > 0)
    {
      int parentIndex = (index - 1) / 2;

      // Check if current node key <= parent key
      if (heap->nodes[index]->key >= heap->nodes[parentIndex]->key)
        {
          break;
        }

      // Swap current node with parent
      HNode *temp = heap->nodes[index];
      heap->nodes[index] = heap->nodes[parentIndex];
      heap->nodes[parentIndex] = temp;

      // Advance index to parent index
      index = parentIndex;
    }
}

// Remove and return minimum element (root) from heap
HNode *
extractMin (Hptr heap)
{
  if (isEmpty (heap))
    {
      perror ("Heap Empty.");
      return NULL;
    }

  // Save minimum node (root)
  HNode *minNode = heap->nodes[0];

  // Move terminal node in heap up to root position
  heap->nodes[0] = heap->nodes[heap->size - 1];

  // Decrement size
  heap->size--;

  // Re-heapify (down from now root new node)
  int index = 0;
  while (index < heap->size)
    {
      int lchild = 2 * index + 1;
      int rchild = 2 * index + 2;
      int smallest = index;

      // Find smallest value between current node and left child
      if (lchild < heap->size
          && heap->nodes[lchild]->key < heap->nodes[smallest]->key)
        {
          smallest = lchild;
        }

      // Find largest value between current node and right child
      if (rchild < heap->size
          && heap->nodes[rchild]->key < heap->nodes[smallest]->key)
        {
          smallest = rchild;
        }

      // If largest == current, heap is properly ordered so break out
      if (smallest == index)
        break;

      // Swap current node with smallest child
      HNode *temp = heap->nodes[index];
      heap->nodes[index] = heap->nodes[smallest];
      heap->nodes[smallest] = temp;

      // Move to the largest child's index
      index = smallest;
    }

  return minNode;
}

// Get minimum element w/o removal
HNode *
peekMin (Hptr heap)
{
  return (heap->nodes[0]);
}
