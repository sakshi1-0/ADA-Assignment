//Implement the Fibonacci sequence using dynamic programming in C or Python. Analyze the time 
//complexity of your implementation and compare it with the time complexity of a recursive implementation.

#include <stdio.h>

int fibonacci(int n) {
    int i, dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for (i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("The %dth Fibonacci number is %d\n", n, fibonacci(n));
    return 0;
}

//Analyze the time complexity of your implementation and compare it with the time complexity of a recursive implementation.

Let T(n) be the time complexity of the dynamic programming implementation of the Fibonacci sequence 
and R(n) be the time complexity of the recursive implementation.

For the dynamic programming implementation, we know that each element of the array is computed only once,
so the total number of computations is equal to n. Therefore, we can express the time complexity as:

T(n) = O(n)

For the recursive implementation, we know that the function is called twice for each value of n, 
leading to a binary tree of function calls. The number of nodes in this tree is equal to 2^n, so the total number of computations is equal to:

R(n) = O(2^n)

As n increases, the number of computations required by the recursive implementation grows exponentially, 
while the number of computations required by the dynamic programming implementation grows linearly. Therefore, 
for large values of n, the dynamic programming implementation will be much faster than the recursive implementation.