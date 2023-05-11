//Implement the rod-cutting problem using dynamic programming in C


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int cutRod(int price[], int n) {
    int dp[n+1];
    dp[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        int max_val = INT_MIN;
        for (int j = 0; j < i; j++) {
            max_val = max(max_val, price[j] + dp[i-j-1]);
        }
        dp[i] = max_val;
    }
    
    return dp[n];
}

int main() {
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(price)/sizeof(price[0]);
    printf("Maximum obtainable value is %d", cutRod(price, n));
    return 0;
}


//Analyze the time and space complexity of your implementation and compare it with the time and space complexity of a naive recursive implementation.

Dynamic Programming:

Let n be the length of the rod and C be the cost array. The time complexity of the dynamic programming solution is O(n^2) because 
we have to fill up an n x n matrix. The space complexity is also O(n^2) because we have to create an n x n matrix to store 
the maximum revenue values for each subproblem.

Naive Recursive Implementation:

The time complexity of the naive recursive implementation is O(2^n) because there are 2^n possible ways to cut the rod.
  The space complexity is O(n) because the maximum depth of the recursion tree is n. However, 
this analysis assumes that the subproblems are not repeated, which is not the case in the naive recursive implementation.
  In practice, the time complexity is much worse because many subproblems are solved repeatedly.

Therefore, the dynamic programming solution is more efficient than the naive recursive implementation for the rod-cutting problem.