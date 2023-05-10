5. Implement a merge sort algorithm for an array of integers.

#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left[], int right[], int left_size, int right_size) {
    int i = 0, j = 0, k = 0;
    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < left_size) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < right_size) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int size) {
    if (size < 2) {
        return;
    }
    int mid = size / 2;
    int* left = (int*)malloc(mid * sizeof(int));
    int* right = (int*)malloc((size-mid) * sizeof(int));
    int i;
    for (i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (i = mid; i < size; i++) {
        right[i-mid] = arr[i];
    }
    merge_sort(left, mid);
    merge_sort(right, size-mid);
    merge(arr, left, right, mid, size-mid);
    free(left);
    free(right);
}

int main() {
    // Sample array
    int arr[] = {5, 1, 4, 2, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using merge sort
    merge_sort(arr, size);

    // Print the sorted array
    int i;
    printf("Sorted array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}