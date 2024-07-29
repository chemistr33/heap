#include <stdio.h>
#include <stdlib.h>
#include "../include/heap.h"
#include "../include/maxheap.h"
#include "../include/minheap.h"

// Function to print a node
void printNode(HNode *node) {
    if (node != NULL) {
        printf("%d ", node->key);
    }
}

int main() {
    // Create a max heap and a min heap
    int capacity = 10;
    Hptr maxHeap = createMax(capacity);
    Hptr minHeap = createMin(capacity);

    // Insert elements into the heaps
    int keys[] = {10, 20, 15, 30, 40, 50, 5, 60};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < numKeys; i++) {
        HNode *node = (HNode *)malloc(sizeof(HNode));
        node->key = keys[i];
        insertMax(maxHeap, node);
        
        HNode *node2 = (HNode *)malloc(sizeof(HNode));
        node2->key = keys[i];
        insertMin(minHeap, node2);
    }

    // Print the heaps
    printf("Max Heap: ");
    printHeap(maxHeap, printNode);
    printf("\n");

    printf("Min Heap: ");
    printHeap(minHeap, printNode);
    printf("\n");

    // Extract elements from the heaps
    printf("Extracting elements from Max Heap: ");
    while (!isEmpty(maxHeap)) {
        HNode *node = extractMax(maxHeap);
        printNode(node);
        free(node);
    }
    printf("\n");

    printf("Extracting elements from Min Heap: ");
    while (!isEmpty(minHeap)) {
        HNode *node = extractMin(minHeap);
        printNode(node);
        free(node);
    }
    printf("\n");

    // Free the heaps
    freeHeap(maxHeap);
    freeHeap(minHeap);

    return 0;
}