#include "appointment.h"
#include <stdio.h>
#include <stdlib.h>

char* scanString() {
    int ArraySize = 10; // Initial size of the array
    char* string = (char*)malloc(ArraySize * sizeof(char)); // Allocate memory for the array
    int index = 0; // Initialize array index
    while (1) {  // Until user presses Enter
        char c = getchar();
        if (c == '\n' || c == EOF) {
            string[index] = '\0'; // End of input
            break;
        } else {
            string[index] = c; // Stores the character in the array
            index++;
            if (index == ArraySize - 1) {// If the array is full, reallocate more memory
                ArraySize *= 2;
                string = (char*)realloc(string, ArraySize * sizeof(char));
            }
        }
    }
    return string;
}