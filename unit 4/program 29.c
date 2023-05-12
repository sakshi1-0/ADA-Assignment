29. Implement the interval scheduling problem using a greedy approach in flowchart

START
Initialize schedule = {} // An empty array to store the selected intervals
Sort the intervals by their finishing times in non-decreasing order
Select the first interval and add it to the schedule
For each subsequent interval:
    If the interval's starting time is greater than or equal to the finishing time of the last interval in the schedule:
        Select the interval and add it to the schedule
    End If
End For
Print the schedule
END




#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

struct Interval {
    int start;
    int finish;
};

int compare(const void* a, const void* b) {
    struct Interval* i1 = (struct Interval*)a;
    struct Interval* i2 = (struct Interval*)b;
    return (i1->finish - i2->finish);
}

void interval_scheduling(struct Interval intervals[], int n) {
    int i, j;
    int last_finish = intervals[0].finish;
    printf("Selected intervals: ");
    printf("(%d, %d) ", intervals[0].start, intervals[0].finish);
    for (i = 1; i < n; i++) {
        if (intervals[i].start >= last_finish) {
            printf("(%d, %d) ", intervals[i].start, intervals[i].finish);
            last_finish = intervals[i].finish;
        }
    }
    printf("\n");
}

int main() {
    struct Interval intervals[MAX_N] = {{1, 3}, {2, 4}, {3, 5}, {4, 6}, {5, 7}, {6, 8}, {7, 9}};
    int n = 7;
    qsort(intervals, n, sizeof(struct Interval), compare);
    interval_scheduling(intervals, n);
    return 0;
}