#include <stdio.h>
#include <limits.h>

int main() {
    // Check the size in bytes
    printf("Size of int: %zu bytes\n", sizeof(int));
    
    // Check the size in bits (8 bits per byte)
    printf("Size of int: %zu bits\n", sizeof(int) * CHAR_BIT);

    // Check the minimum and maximum values for context
    printf("Minimum value (INT_MIN): %d\n", INT_MIN);
    printf("Maximum value (INT_MAX): %d\n", INT_MAX);
    
    return 0;
}