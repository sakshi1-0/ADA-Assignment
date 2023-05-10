.  Implement a selection sort algorithm for an array of integers.

#include <stdio.h>

void selection_sort(int arr[], int size) {
    int i, j, min_idx, temp;
    for (i = 0; i < size-1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    // Sample array
    int arr[] = {5, 1, 4, 2, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using selection sort
    selection_sort(arr, size);

    // Print the sorted array
    int i;
    printf("Sorted array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}