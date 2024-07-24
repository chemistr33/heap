#include "maxHeap.h"
#include <stdio.h>
#include <stdlib.h>

// Opaque Heap Structure
struct Heap
{
  HeapNode **nodes;
  int capacity;
  int size;
};

/////////////////////////////////// Review /////////////////////////////////////

Heap *
createHeap (int capacity)
{
  Heap *heap = (Heap *)malloc (sizeof (Heap));
  heap->nodes = (HeapNode **)malloc (capacity * sizeof (HeapNode *));
  heap->capacity = capacity;
  heap->size = 0;
  return heap;
}

void
swap (HeapNode **a, HeapNode **b)
{
  HeapNode *temp = *a;
  *a = *b;
  *b = temp;
}

void
heapifyUp (Heap *heap, int index)
{
  int parentIndex = (index - 1) / 2;
  if (index > 0 && heap->nodes[index]->key > heap->nodes[parentIndex]->key)
    {
      swap (&heap->nodes[index], &heap->nodes[parentIndex]);
      heapifyUp (heap, parentIndex);
    }
}

void
heapifyDown (Heap *heap, int index)
{
  int largest = index;
  int leftChild = 2 * index + 1;
  int rightChild = 2 * index + 2;

  if (leftChild < heap->size
      && heap->nodes[leftChild]->key > heap->nodes[largest])
    largest = leftChild;

  if (rightChild < heap->size
      && heap->nodes[rightChild]->key > heap->nodes[largest])
    largest = rightChild;

  if (largest != index)
    {
      swap (&heap->nodes[index], &heap->nodes[largest]);
      heapifyDown (heap, largest);
    }
}

void
insert (Heap *heap, HeapNode *node)
{
  if (heap->size == heap->capacity)
    {
      printf ("Heap overflow\n");
      return;
    }
  heap->nodes[heap->size] = node;
  heapifyUp (heap, heap->size);
  heap->size++;
}

HeapNode *
extractMax (Heap *heap)
{
  if (heap->size <= 0)
    {
      printf ("Heap underflow\n");
      return NULL;
    }
  if (heap->size == 1)
    {
      heap->size--;
      return heap->nodes[0];
    }

  HeapNode *root = heap->nodes[0];
  heap->nodes[0] = heap->nodes[heap->size - 1];
  heap->size--;
  heapifyDown (heap, 0);

  return root;
}

HeapNode *
peek (Heap *heap)
{
  if (heap->size <= 0)
    {
      printf ("Heap is empty\n");
      return NULL;
    }
  return heap->nodes[0];
}

int
size (Heap *heap)
{
  return heap->size;
}

int
isEmpty (Heap *heap)
{
  return heap->size == 0;
}

void
printHeap (Heap *heap, void (*printNode) (HeapNode *))
{
  for (int i = 0; i < heap->size; i++)
    {
      printNode (heap->nodes[i]);
    }
  printf ("\n");
}

void
freeHeap (Heap *heap)
{
  free (heap->nodes);
  free (heap);
}