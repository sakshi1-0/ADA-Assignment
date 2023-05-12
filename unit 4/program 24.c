24. Implement the activity selection problem using a greedy approach in C

#include <stdio.h>
#include <stdlib.h>

// Activity structure
struct activity {
    int start;
    int end;
};

// Function to compare two activities by their end times
int compare_activities(const void* a, const void* b) {
    const struct activity* activity_a = (const struct activity*)a;
    const struct activity* activity_b = (const struct activity*)b;
    return activity_a->end - activity_b->end;
}

// Function to select maximum number of activities that can be performed by a single person
void select_activities(struct activity activities[], int n) {
    // Sort the activities by their end times
    qsort(activities, n, sizeof(struct activity), compare_activities);
    
    // Select the first activity
    int i = 0;
    printf("Selected Activity: (%d, %d)\n", activities[i].start, activities[i].end);
    
    // Select the remaining activities
    int j;
    for (j = 1; j < n; j++) {
        if (activities[j].start >= activities[i].end) {
            printf("Selected Activity: (%d, %d)\n", activities[j].start, activities[j].end);
            i = j;
        }
    }
}

// Driver code
int main() {
    // Input the number of activities
    int n;
    printf("Enter the number of activities: ");
    scanf("%d", &n);
    
    // Input the start and end times of each activity
    struct activity activities[n];
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter the start and end times of activity %d: ", i+1);
        scanf("%d %d", &activities[i].start, &activities[i].end);
    }
    
    // Select the maximum number of activities that can be performed by a single person
    select_activities(activities, n);
    
    return 0;
}