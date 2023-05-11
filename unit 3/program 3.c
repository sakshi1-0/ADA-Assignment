/Implement the knapsack problem using dynamic programming in C 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n+1][W+1];
 
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            }
            else if (wt[i-1] <= w) {
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
            }
            else {
                K[i][w] = K[i-1][w];
            }
        }
    }
 
    return K[n][W];
}
 
int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    printf("Maximum value that can be put in a knapsack of capacity %d is %d\n", W, knapsack(W, wt, val, n));
    return 0;
}


//Analyze the time and space complexity of your implementation and compare it with the time and space complexity of a greedy algorithm.

The time complexity of the dynamic programming solution for the knapsack problem is O(nW), 
where n is the number of items and W is the capacity of the knapsack. 
  The space complexity is also O(nW) as we need to store the maximum value for all possible subproblems.

The time complexity of a greedy algorithm for the knapsack problem depends on the specific approach used. 
  For example, a greedy algorithm that chooses items with the highest value-to-weight ratio until 
  the knapsack is full has a time complexity of O(n log n) if the items are sorted by this ratio, 
or O(n^2) if the ratios need to be computed for each item. The space complexity of a greedy algorithm 
is O(1) as we only need to store the current total value and weight of the items selected.

In terms of performance, the dynamic programming solution can handle larger problem sizes and provides 
the optimal solution, while a greedy algorithm may provide a suboptimal solution but is faster for smaller problem sizes.