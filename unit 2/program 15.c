15. Implement a divide-and-conquer algorithm for finding the maximum subarray sum of a given array of integers.

#include <stdio.h>
#include <stdlib.h>

typedef struct max_subarray {
    int start;
    int end;
    int sum;
} MaxSubarray;

MaxSubarray find_max_crossing_subarray(int* arr, int low, int mid, int high) {
    int left_sum = -2147483647; // negative infinity
    int sum = 0;
    int max_left;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = -2147483647; // negative infinity
    sum = 0;
    int max_right;
    for (int j = mid + 1; j <= high; j++) {
        sum += arr[j];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = j;
        }
    }

    MaxSubarray max_subarray = {max_left, max_right, left_sum + right_sum};
    return max_subarray;
}

MaxSubarray find_max_subarray(int* arr, int low, int high) {
    if (low == high) {
        MaxSubarray max_subarray = {low, high, arr[low]};
        return max_subarray;
    } else {
        int mid = (low + high) / 2;
        MaxSubarray left_subarray = find_max_subarray(arr, low, mid);
        MaxSubarray right_subarray = find_max_subarray(arr, mid + 1, high);
        MaxSubarray crossing_subarray = find_max_crossing_subarray(arr, low, mid, high);

        if (left_subarray.sum >= right_subarray.sum && left_subarray.sum >= crossing_subarray.sum) {
            return left_subarray;
        } else if (right_subarray.sum >= left_subarray.sum && right_subarray.sum >= crossing_subarray.sum) {
            return right_subarray;
        } else {
            return crossing_subarray;
        }
    }
}

int main() {
    int arr[] = { -2, -5, 6, -2, -3, 1, 5, -6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    MaxSubarray max_subarray = find_max_subarray(arr, 0, n - 1);
    printf("The maximum subarray is from index %d to %d with sum %d\n", max_subarray.start, max_subarray.end, max_subarray.sum);
    return 0;
}