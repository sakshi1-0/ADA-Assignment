13. Implement a recursive algorithm for computing the greatest common divisor of two integers using divide-and-conquer.

#include <stdio.h>

int gcd(int a, int b) {
    // Base case
    if (a == 0 || b == 0) {
        return (a == 0) ? b : a;
    }
    
    // Divide
    int a_prime = (a > b) ? a - b : a;
    int b_prime = (b > a) ? b - a : b;
    
    // Conquer
    int gcd_prime = gcd(a_prime, b_prime);
    
    // Combine
    return gcd_prime;
}

int main() {
    int a = 18, b = 24;
    int result = gcd(a, b);
    printf("The GCD of %d and %d is: %d\n", a, b, result);
    return 0;
}