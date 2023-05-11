//Implement the matrix chain multiplication problem using dynamic programming in C or Python. 

#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

int matrixChainOrder(int p[], int n) {
    int m[n][n];
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INF;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }
    return m[1][n-1];
}

int main() {
    int arr[] = {10, 20, 30, 40, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Minimum number of multiplications is %d", matrixChainOrder(arr, n));
    return 0;
}


//Analyze the time and space complexity of your implementation and compare it with the time and space complexity of a naive recursive implementation.

The time complexity of the dynamic programming solution for the matrix chain multiplication problem is O(n^3),
where n is the number of matrices in the chain. This is because the solution requires computing values 
for each subproblem once and then reusing those values when computing solutions to larger subproblems. 
  The number of subproblems is proportional to the number of pairs of matrices in the chain, 
which is n^2, and each subproblem requires O(n) time to compute.

The space complexity of the dynamic programming solution is also O(n^2), 
since we need to store the values for each subproblem in a 2D array.

The naive recursive solution has a time complexity of O(2^n), 
where n is the number of matrices in the chain. This is because the solution requires computing values for each possible partition of the matrix chain,
resulting in an exponential number of subproblems. The space complexity of the naive recursive solution is also O(n^2), 
since we need to store the values for each subproblem in a 2D array. However, 
since the recursive solution requires computing exponentially more subproblems, the space complexity becomes impractical for large values of n.

Overall, the dynamic programming solution has much better time complexity than the naive recursive solution, and comparable space complexity.