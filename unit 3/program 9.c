//Develop a dynamic programming algorithm to find the longest increasing subsequence in C 

#include <stdio.h>
#include <stdlib.h>

int lis(int arr[], int n) {
    int *dp = (int*) malloc(sizeof(int) * n);
    int i, j, max = 0;

    for(i = 0; i < n; i++) {
        dp[i] = 1; // every element is a subsequence of length 1
        for(j = 0; j < i; j++) {
            if(arr[i] > arr[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1; // increase length of subsequence by 1
            }
        }
        if(dp[i] > max) {
            max = dp[i]; // update maximum subsequence length
        }
    }
    free(dp);
    return max;
}

int main() {
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of longest increasing subsequence: %d\n", lis(arr, n));
    return 0;
}

//Analyze the time and space complexity of your implementation and compare it with the time and space complexity of a brute-force approach.the analysis of time and space complexity for the dynamic programming approach and brute-force approach for finding the longest increasing subsequence:

Dynamic Programming Approach:

Time Complexity: O(n^2)
The outer loop runs n times and the inner loop also runs up to n times, resulting in a time complexity of O(n^2).
  
Space Complexity: O(n)
We create an array of size n to store the longest increasing subsequence ending at each index.
  
  
Brute-Force Approach:

Time Complexity: O(2^n)
The algorithm will generate all possible subsequences of the given sequence, which is 2^n. 
Then, for each subsequence, we check if it is increasing, which takes O(n) time.
  
Space Complexity: O(n)
We need to store the current subsequence being generated, which has a maximum size of n.
  
As we can see, the dynamic programming approach has a significantly lower time complexity 
than the brute-force approach. Additionally, the space complexity of the dynamic programming approach
is also lower than that of the brute-force approach. Therefore, the dynamic programming approach is 
much more efficient than the brute-force approach for finding the longest increasing subsequence.