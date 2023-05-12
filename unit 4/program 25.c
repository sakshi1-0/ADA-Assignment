25. Implement the knapsack problem using a greedy approach in C 

#include <stdio.h>
#include <stdlib.h>

// Item structure
struct item {
    int weight;
    int value;
    float density;
};

// Function to compare two items by their density
int compare_items(const void* a, const void* b) {
    const struct item* item_a = (const struct item*)a;
    const struct item* item_b = (const struct item*)b;
    if (item_a->density > item_b->density) {
        return -1;
    } else if (item_a->density < item_b->density) {
        return 1;
    } else {
        return 0;
    }
}

// Function to solve the fractional knapsack problem using a greedy approach
float fractional_knapsack(struct item items[], int n, int capacity) {
    // Compute the density of each item
    int i;
    for (i = 0; i < n; i++) {
        items[i].density = (float)items[i].value / items[i].weight;
    }
    
    // Sort the items by their density
    qsort(items, n, sizeof(struct item), compare_items);
    
    // Fill the knapsack with items of maximum total value
    float total_value = 0.0;
    i = 0;
    while (capacity > 0 && i < n) {
        if (items[i].weight <= capacity) {
            total_value += items[i].value;
            capacity -= items[i].weight;
        } else {
            total_value += capacity * items[i].density;
            capacity = 0;
        }
        i++;
    }
    
    return total_value;
}

// Driver code
int main() {
    // Input the number of items and the maximum capacity of the knapsack
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &capacity);
    
    // Input the weight and value of each item
    struct item items[n];
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter the weight and value of item %d: ", i+1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }
    
    // Solve the fractional knapsack problem using a greedy approach
    float total_value = fractional_knapsack(items, n, capacity);
    
    // Output the maximum total value of items that can be put into the knapsack
    printf("The maximum total value of items that can be put into the knapsack is: %f\n", total_value);
    
    return 0;
}