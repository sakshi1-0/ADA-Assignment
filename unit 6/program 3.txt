# Implement a branch and bound algorithm for the Traveling Salesman Problem, and analyze its running time complexity.

import sys
import math

def tsp(graph):
    # Initialize variables
    n = len(graph)
    visited = [False] * n
    path = []
    min_path = [None] * n
    min_cost = sys.maxsize
    curr_cost = 0

    # Define helper function for finding minimum edge cost
    def get_min_cost(curr_vertex):
        min_edge_cost = sys.maxsize
        min_edge_vertex = -1
        for v in range(n):
            if graph[curr_vertex][v] < min_edge_cost and not visited[v]:
                min_edge_cost = graph[curr_vertex][v]
                min_edge_vertex = v
        return min_edge_vertex, min_edge_cost

    # Define helper function for calculating lower bound of minimum cost
    def calculate_lower_bound(curr_vertex):
        total_cost = curr_cost
        for i in range(curr_vertex+1, n):
            _, edge_cost = get_min_cost(path[i-1])
            total_cost += edge_cost
        return total_cost

    # Define recursive function to search for optimal solution
    def search(curr_vertex):
        nonlocal curr_cost, min_cost
        if curr_vertex == n:
            # Update minimum cost and path if a better solution is found
            _, edge_cost = get_min_cost(path[-1])
            curr_cost += edge_cost
            if curr_cost < min_cost:
                min_cost = curr_cost
                min_path[:] = path[:]
            curr_cost -= edge_cost
            return
        for v in range(n):
            if not visited[v]:
                path.append(v)
                visited[v] = True
                curr_cost += graph[path[-2]][v] if len(path) > 1 else 0
                if calculate_lower_bound(curr_vertex) < min_cost:
                    search(curr_vertex+1)
                curr_cost -= graph[path[-2]][v] if len(path) > 1 else 0
                visited[v] = False
                path.pop()

    # Start search from vertex 0
    path.append(0)
    visited[0] = True
    search(1)

    # Return minimum cost and path
    return min_cost, min_path