//Implement a dynamic programming algorithm to find the maximum sum subarray in C 

#include <stdio.h>

int maxSubArraySum(int arr[], int n)
{
    int max_so_far = arr[0], curr_max = arr[0];
 
    for (int i = 1; i < n; i++)
    {
        curr_max = (arr[i] > curr_max + arr[i]) ? arr[i] : curr_max + arr[i];
        max_so_far = (max_so_far > curr_max) ? max_so_far : curr_max;
    }
    return max_so_far;
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max_sum = maxSubArraySum(arr, n);
    printf("Maximum contiguous sum is %d", max_sum);
    return 0;
}

//Analyze the time and space complexity of your implementation and compare it with the time and space complexity of a naive brute-force approach.

The time and space complexity of the dynamic programming algorithm to find the maximum sum subarray in an array of size n is O(n)
  because it requires a single pass through the array, updating a running sum and keeping track of the maximum sum seen so far.

In contrast, the naive brute-force approach involves checking all possible subarrays, resulting in a time complexity of O(n^2)
  and a space complexity of O(1). Therefore, the dynamic programming approach is more efficient than the naive approach in terms of both time and space complexity.