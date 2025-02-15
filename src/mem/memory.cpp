/*
special AVR arch on arduino:
__bss_end: Marks the end of the .bss section (uninitialized global/static variables) and the start of the heap.
__heap_start: Essentially the same as __bss_end on AVR, indicating where heap allocations begin.
__brkval: Points to the end of the heap, i.e., the next available address after the last malloc() allocation. If no dynamic memory has been allocated, it remains NULL or 0.
_heap_start, __heap_end: Define the boundaries of the heap memory.

__heap_start: the beginning of the heap section.

__brkval: the last memory address pointer used by the heap


__bss_start, __bss_end: Define the start and end of the .bss section.
__data_start, __data_end: Define the start and end of the .data section (initialized global/static variables).
malloc
https://www.nongnu.org/avr-libc/user-manual/malloc.html

https://docs.arduino.cc/learn/programming/memory-guide/
*/

#include "memory.hpp"



int freeMemory() {
    int free_memory;
    if ((int)__brkval == 0) { //(int) converts pointers to integers to do calculations
        free_memory = ((int)&free_memory) - ((int)&__bss_end); // the difference between the current stack address and the heap start address provides an estimate of the free bytes between stack and heap.
    } else {
        free_memory = ((int)&free_memory) - ((int)__brkval);
    }  
    return free_memory;
}


int freeHeap() {
    return ((int)&__heap_start) - ((int)__brkval); // __heap_start is the start of the heap, and __brkval is the currently position of the heap, soo the difference between them is the remaining heap
}

int usedHeap() {
    return ((int)__brkval) - ((int)&__heap_start); // __brkval is the currently position of the heap, and __heap_start is the start of the heap, soo the difference between them is the used heap
}

int heapSize() {
    return ((int)&__heap_end) - ((int)&__heap_start); // __heap_end is the end of the heap, and __heap_start is the start of the heap, soo the difference between them is the heap size
}

int usedMemory() {
    return ((int)&__bss_end) - ((int)&__data_end); // __bss_end is the end of the .bss section, and __data_end is the end of the .data section, soo the difference between them is the used memory, u should note that it's an hirarchial calculation
} 

int largestFreeBlock() {
    char *heap_top = (char *)sbrk(0);
    char stack_bottom;
    return &stack_bottom - heap_top; // the difference between the stack bottom and the heap top is the largest free block
}


/*Conceptually, the calculation is based on the fact that free memory is the space separating the stack (which grows to lower addresses) from the heap (which grows to higher addresses).*/




/*
MEMORY OPTIMIZATION:
1. Use the smallest data type possible, do not use long (4 bytes) if you can use int (2 bytes) or char (1 byte).
2. Use static or const variables whenever possible
3. Minimize the declaration of global variables
4. Use the F() macro to store strings in flash memory
5. Use the PROGMEM attribute to store large data in flash memory so u won't consume the RAM
6. Use the PSTR() macro to store strings in flash memory
7. Don't call malloc, calloc, realloc too much, they are slow and can cause memory fragmentation

eeprom and flash memory have limited write cycles, so use them wisely, circa 100,000 write cycles for eeprom and circa 10,000 write cycles for flash memory
*/
