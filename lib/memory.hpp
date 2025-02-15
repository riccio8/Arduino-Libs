#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// AVR (like ATmega328p) specific memory var, other arch may have different names
char __bss_start;
char __bss_end;
char __heap_start;
char* __brkval;
char __heap_end;


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
int largestFreeBlock();

#ifdef __cplusplus
}
#endif
