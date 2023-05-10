11. Implement a recursive algorithm for computing the factorial of a given positive integer using divide-and-conquer.

#include <stdio.h>

int factorial(int n) {
    // Base case
    if (n == 0) {
        return 1;
    }
    
    // Divide
    int k = n / 2;
    
    // Conquer
    int left_factorial = factorial(k);
    int right_factorial = factorial(n - k);
    
    // Combine
    return left_factorial * right_factorial * ((n % 2 == 0) ? 1 : n);
}

int main() {
    int n = 5;
    int result = factorial(n);
    printf("%d! = %d\n", n, result);
    return 0;
}