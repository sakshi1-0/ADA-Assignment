1. Implement a binary search algorithm for an array of integers.

#include <stdio.h>

int binary_search(int arr[], int size, int x) {
    int low = 0, high = size - 1, mid;
    
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        else if (arr[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    // If element is not found in the array
    return -1;
}

int main() {
    // Sample sorted array
    int arr[] = {2, 4, 7, 8, 10, 12, 15};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Find the index of the element 8
    int index = binary_search(arr, size, 8);

    // Print the result
    if (index != -1) {
        printf("Element found at index %d.", index);
    }
    else {
        printf("Element not found.");
    }

    return 0;
}