30. Implement the fractional knapsack problem using a greedy approach in flowchart

START
Input n, W and items[n], where items[i] = {vi, wi} is the value and weight of item i
For each item:
    Compute the value per unit weight (vi/wi)
Sort the items in non-increasing order of value per unit weight
Initialize profit = 0
Initialize weight = 0
For each item:
    If weight + item weight <= W:
        Add item to knapsack
        Add item weight to weight
        Add item value to profit
    Else:
        Calculate fraction of item that fits into knapsack
        Add fraction of item weight to weight
        Add fraction of item value to profit
        Stop loop
End For
Print profit
END




#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

struct Item {
    int value;
    int weight;
};

int compare(const void* a, const void* b) {
    struct Item* i1 = (struct Item*)a;
    struct Item* i2 = (struct Item*)b;
    double ratio1 = (double)i1->value / i1->weight;
    double ratio2 = (double)i2->value / i2->weight;
    if (ratio1 < ratio2) {
        return 1;
    } else if (ratio1 > ratio2) {
        return -1;
    } else {
        return 0;
    }
}

double fractional_knapsack(struct Item items[], int n, int W) {
    qsort(items, n, sizeof(struct Item), compare);
    int i;
    double profit = 0.0;
    int weight = 0;
    for (i = 0; i < n; i++) {
        if (weight + items[i].weight <= W) {
            weight += items[i].weight;
            profit += items[i].value;
        } else {
            int remaining_weight = W - weight;
            double fraction = (double)remaining_weight / items[i].weight;
            weight += remaining_weight;
            profit += fraction * items[i].value;
            break;
        }
    }
    return profit;
}

int main() {
    struct Item items[MAX_N] = {{60, 10}, {100, 20}, {120, 30}};
    int n = 3;
    int W = 50;
    double max_profit = fractional_knapsack(items, n, W);
    printf("Maximum profit: %.2f\n", max_profit);
    return 0;
}