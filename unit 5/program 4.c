# Implement Bellman-Ford algorithm to find the shortest path between two nodes in a graph with negative weight edges in  Python.

INF = float('inf')

def bellman_ford(graph, source):
    # Initialize distance of all nodes to infinity, except for source node
    distances = {node: INF for node in graph}
    distances[source] = 0
    
    # Iterate through all edges n-1 times
    for _ in range(len(graph) - 1):
        for u in graph:
            for v, weight in graph[u].items():
                if distances[u] + weight < distances[v]:
                    distances[v] = distances[u] + weight
    
    # Check for negative weight cycles
    for u in graph:
        for v, weight in graph[u].items():
            if distances[u] + weight < distances[v]:
                print("Graph contains negative weight cycle")
                return None
    
    # Return the distances dictionary
    return distances