#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;        
    int size;         
    int capacity;     
} DynamicArray;

// Function to initialize the dynamic array
DynamicArray* createArray(int initialCapacity) {
    DynamicArray *arr = (DynamicArray*)malloc(sizeof(DynamicArray));
    arr->data = (int*)malloc(initialCapacity * sizeof(int));
    arr->size = 0;
    arr->capacity = initialCapacity;
    return arr;
}

// Resize the array when capacity is reached
void resizeArray(DynamicArray *arr) {
    arr->capacity *= 2;  
    arr->data = (int*)realloc(arr->data, arr->capacity * sizeof(int));
}

// Push method to add an element at the end of the dynamic array
void push(DynamicArray *arr, int value) {
    if (arr->size == arr->capacity) {
        resizeArray(arr);  
    }
    arr->data[arr->size] = value;  
    arr->size++;
}

// Function to pop the last element from the array
int pop(DynamicArray *arr) {
    if (arr->size == 0) {
        fprintf(stderr, "Error: Attempt to pop from an empty array.\n");
        return -1;  // Or handle error appropriately
    }
    int value = arr->data[arr->size - 1];  // Get the last element
    arr->size--;  // Decrease the size, effectively removing the last element

    // Optional: Shrink array if size is much smaller than capacity (e.g., 1/4 capacity)
    if (arr->size > 0 && arr->size <= arr->capacity / 4) {
        arr->capacity /= 2;
        arr->data = (int*)realloc(arr->data, arr->capacity * sizeof(int));
    }

    return value;  // Return the popped value
}

// Function to free the array's memory
void freeArray(DynamicArray *arr) {
    free(arr->data);
    free(arr);
}

// Demonstration
int main() {
    DynamicArray *arr = createArray(4);

    // Push elements
    for (int i = 0; i < 8; i++) {
        push(arr, i);
        printf("Added %d, size: %d, capacity: %d\n", i, arr->size, arr->capacity);
    }

    // Pop elements
    for (int i = 0; i < 8; i++) {
        int value = pop(arr);
        printf("Popped %d, size: %d, capacity: %d\n", value, arr->size, arr->capacity);
    }

    // Clean up
    freeArray(arr);
    return 0;
}
