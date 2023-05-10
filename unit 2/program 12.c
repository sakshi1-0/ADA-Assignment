12. Implement a recursive algorithm for computing the Fibonacci sequence using divide-and-conquer.

#include <stdio.h>

int fibonacci(int n) {
    // Base case
    if (n <= 1) {
        return n;
    }
    
    // Divide
    int k = (n + 1) / 2;
    
    // Conquer
    int fib_k = fibonacci(k);
    int fib_k_minus_1 = fibonacci(k - 1);
    int fib_k_plus_1 = fib_k + fib_k_minus_1;
    
    // Combine
    if (n % 2 == 0) {
        return fib_k * (2 * fib_k_minus_1 + fib_k);
    } else {
        return fib_k_plus_1 * fib_k_plus_1 + fib_k_minus_1 * fib_k_minus_1;
    }
}

int main() {
    int n = 7;
    int result = fibonacci(n);
    printf("The %dth Fibonacci number is: %d\n", n, result);
    return 0;
}