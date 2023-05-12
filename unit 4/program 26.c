26. Implement the coin change problem using a greedy approach in C 

#include <stdio.h>

// Function to solve the coin change problem using a greedy approach
void coin_change(int coins[], int n, int amount) {
    // Initialize the count of coins to 0
    int count[n];
    int i;
    for (i = 0; i < n; i++) {
        count[i] = 0;
    }
    
    // Greedily select coins of largest denomination first
    i = 0;
    while (amount > 0 && i < n) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count[i]++;
        }
        i++;
    }
    
    // Output the count of each coin used
    if (amount == 0) {
        printf("The minimum number of coins needed is: ");
        for (i = 0; i < n; i++) {
            printf("%d ", count[i]);
        }
        printf("\n");
    } else {
        printf("It is not possible to make change for the given amount.\n");
    }
}

// Driver code
int main() {
    // Input the number of coins and their denominations
    int n;
    printf("Enter the number of coins: ");
    scanf("%d", &n);
    int coins[n];
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter the denomination of coin %d: ", i+1);
        scanf("%d", &coins[i]);
    }
    
    // Sort the coins in decreasing order
    int j;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (coins[j] > coins[i]) {
                int temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }
    
    // Input the amount to be changed
    int amount;
    printf("Enter the amount to be changed: ");
    scanf("%d", &amount);
    
    // Solve the coin change problem using a greedy approach
    coin_change(coins, n, amount);
    
    return 0;
}