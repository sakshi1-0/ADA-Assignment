27. Develop a new greedy algorithm to solve the job scheduling problem and analyze its efficiency and effectiveness in C

#include <stdio.h>

struct job {
    int id;
    int processing_time;
    int deadline;
};

// Function to solve the job scheduling problem using the EDF algorithm
void schedule_jobs(struct job jobs[], int n) {
    // Sort the jobs in non-decreasing order of their deadlines
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (jobs[j].deadline < jobs[i].deadline) {
                struct job temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            } else if (jobs[j].deadline == jobs[i].deadline && jobs[j].processing_time < jobs[i].processing_time) {
                struct job temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            }
        }
    }
    
    // Schedule the jobs in order of their deadlines
    int current_time = 0;
    int missed_deadlines = 0;
    for (i = 0; i < n; i++) {
        if (current_time + jobs[i].processing_time <= jobs[i].deadline) {
            current_time += jobs[i].processing_time;
        } else {
            missed_deadlines++;
        }
    }
    
    // Output the number of missed deadlines
    printf("The number of missed deadlines is: %d\n", missed_deadlines);
}

// Driver code
int main() {
    // Input the number of jobs and their processing times and deadlines
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    struct job jobs[n];
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter the processing time and deadline of job %d: ", i+1);
        scanf("%d %d", &jobs[i].processing_time, &jobs[i].deadline);
        jobs[i].id = i+1;
    }
    
    // Solve the job scheduling problem using the EDF algorithm
    schedule_jobs(jobs, n);
    
    return 0;
}