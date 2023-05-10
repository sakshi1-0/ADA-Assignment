7.  Implement a linear search algorithm for an array of integers.

#include <stdio.h>

int linear_search(int arr[], int size, int key) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1; // key not found
}

int main() {
    // Sample array
    int arr[] = {5, 1, 4, 2, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Search for a key using linear search
    int key = 4;
    int index = linear_search(arr, size, key);

    // Print the search result
    if (index == -1) {
        printf("Key not found.\n");
    } else {
        printf("Key found at index %d.\n", index);
    }

    return 0;
}