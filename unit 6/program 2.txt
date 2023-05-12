# Develop a greedy algorithm for the Job Scheduling Problem, 


def job_scheduling(jobs):
    # Sort jobs in increasing order of deadlines
    sorted_jobs = sorted(jobs, key=lambda x: x[1])
    
    # Initialize variables
    schedule = []
    completion_time = 0
    
    # Iterate through jobs and schedule if feasible
    for job in sorted_jobs:
        processing_time, deadline = job
        if completion_time + processing_time <= deadline:
            schedule.append(job)
            completion_time += processing_time
    
    # Return schedule and total completion time
    return schedule, completion_time

# Example usage
jobs = [(3, 6), (2, 8), (4, 7), (1, 10), (2, 5)]
schedule, completion_time = job_scheduling(jobs)
print("Schedule:", schedule)
print("Completion time:", completion_time)

"""
and evaluate its effectiveness on a variety of input instances.
The Job Scheduling Problem (JSP) involves scheduling a set of jobs on a single machine to minimize the total completion time. 
Each job has a processing time and a deadline, and must be completed by its deadline to avoid incurring a penalty.
A simple greedy algorithm for JSP is to sort the jobs by their deadlines in ascending order, 
and then schedule each job as early as possible while still meeting its deadline. 
This algorithm is called the Earliest Deadline First (EDF) algorithm.
To evaluate the effectiveness of the EDF algorithm, we can generate a variety of input instances with different characteristics,
such as the number of jobs, the processing times, and the deadlines.
We can then compare the performance of the EDF algorithm to other algorithms,
such as the Optimal algorithm which solves the JSP optimally but is computationally expensive.
"""