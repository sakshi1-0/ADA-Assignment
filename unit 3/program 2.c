//Implement the longest common subsequence problem using dynamic programming in C.


#include <stdio.h>
#include <string.h>
#define MAXLEN 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

void LCS(char X[], char Y[], int m, int n) {
    int L[m+1][n+1];
    int i, j;

    // Building the LCS matrix
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if (X[i-1] == Y[j-1]) {
                L[i][j] = L[i-1][j-1] + 1;
            } else {
                L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
    }

    // Printing the LCS
    int index = L[m][n];
    char lcs[index+1];
    lcs[index] = '\0';
    i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i-1] == Y[j-1]) {
            lcs[index-1] = X[i-1];
            i--, j--, index--;
        } else if (L[i-1][j] > L[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("The longest common subsequence is %s.\n", lcs);
}

int main() {
    char X[MAXLEN], Y[MAXLEN];

    printf("Enter the first string: ");
    scanf("%s", X);

    printf("Enter the second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    LCS(X, Y, m, n);

    return 0;
}



//Analyze the time and space complexity of your implementation and compare it with the time and space complexity of a naive recursive implementation.
To analyze the time complexity of the dynamic programming solution for the longest common subsequence problem in C,
we can use the following mathematical expression:

Let m and n be the lengths of the input strings X and Y, respectively. 
Let T(m,n) be the time complexity of the dynamic programming solution.

The time complexity of filling in the dynamic programming table using the nested for loop is O(mn). 
The time complexity of building the longest common subsequence from the dynamic programming table is O(m+n).
Therefore, the overall time complexity of the dynamic programming solution is:

T(m,n) = O(mn) + O(m+n)
= O(mn)

Thus, the time complexity of the dynamic programming solution is O(mn).

To analyze the time complexity of the naive recursive solution for the longest common subsequence problem,
we can use the following mathematical expression:

Let m and n be the lengths of the input strings X and Y, respectively. Let T(m,n) be the time complexity of the naive recursive solution.

The recursive function will call itself twice at each level, except for the base cases where either m or n is zero. Therefore, 
the number of recursive calls is exponential in the length of the input strings.

Assuming that the cost of each recursive call is constant, the time complexity of the naive recursive solution can be expressed as:

T(m,n) = 2T(m-1,n-1) + O(1)

Using the Master Theorem, we can determine that the time complexity of the naive recursive solution is O(2^(m+n)).

Thus, the time complexity of the dynamic programming solution is significantly better than the time complexity of the naive recursive solution.