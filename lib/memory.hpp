#pragma once

#ifdef __cplusplus
extern "C" {
#endif





// Returns the amount of free memory between the heap and the stack.
int freeMemory();

// Returns the remaining available heap space.
int freeHeap();

// Returns the currently used heap size.
int usedHeap();

// Returns the total heap size.
int heapSize();

// Returns the memory used by initialized and uninitialized global/static variables.
int usedMemory();

// Returns the largest free block of memory.
// int largestFreeBlock();

#ifdef __cplusplus
}
#endif
