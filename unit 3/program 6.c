//Develop a dynamic programming algorithm for the edit distance problem in C or Python. 

#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

int min(int a, int b, int c) {
    if (a < b && a < c) {
        return a;
    } else if (b < c) {
        return b;
    } else {
        return c;
    }
}

int editDistance(char s1[], char s2[], int m, int n) {
    int dp[MAX_LEN][MAX_LEN];
    
    // Initialize the dp table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
            }
        }
    }
    
    return dp[m][n];
}

int main() {
    char s1[MAX_LEN], s2[MAX_LEN];
    printf("Enter string 1: ");
    scanf("%s", s1);
    printf("Enter string 2: ");
    scanf("%s", s2);
    int m = strlen(s1);
    int n = strlen(s2);
    printf("The minimum edit distance is: %d\n", editDistance(s1, s2, m, n));
    return 0;
}


//Analyze the time and space complexity of your implementation and compare it with the time and space complexity of a naive recursive implementation.

The time complexity of the dynamic programming algorithm for the edit distance problem is O(m*n),
where m and n are the lengths of the two strings being compared. This is because we need to fill up a 2D matrix of size (m+1) x (n+1), 
and each cell takes constant time to compute.

The space complexity of the dynamic programming algorithm is also O(m*n), as we need to store the 2D matrix in memory. 
However, we can optimize the space complexity to O(n) by only storing two rows of the matrix at a time, 
and updating them iteratively as we move down the matrix.

In comparison, the time complexity of a naive recursive implementation would be exponential,
as we would need to explore all possible combinations of edits. The space complexity would also be exponential,
as each recursive call would add a new level to the call stack.

Therefore, the dynamic programming algorithm is much more efficient than 
a naive recursive implementation for the edit distance problem, both in terms of time and space complexity.