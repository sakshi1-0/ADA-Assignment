17. Implement a divide-and-conquer algorithm for finding the kth largest element in an unsorted array of integers.

#include <stdio.h>
#include <stdlib.h>

int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] >= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

int kth_largest(int* arr, int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }
    int p = partition(arr, low, high);
    int size = p - low + 1;
    if (size == k) {
        return arr[p];
    } else if (size > k) {
        return kth_largest(arr, low, p - 1, k);
    } else {
        return kth_largest(arr, p + 1, high, k - size);
    }
}

int main() {
    int arr[] = {3, 2, 1, 5, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    int kth = kth_largest(arr, 0, n - 1, k);
    printf("The %dth largest element is %d\n", k, kth);
    return 0;
}