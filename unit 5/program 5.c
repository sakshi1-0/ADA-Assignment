#  Implement the Floyd-Warshall algorithm to find the shortest path between all pairs of nodes in a graph in Python.

def floyd_warshall(graph):
    n = len(graph)
    dist = [[float('inf')] * n for _ in range(n)]
    
    # Initialize distance matrix with edge weights
    for u in range(n):
        for v in range(n):
            dist[u][v] = graph[u][v]
    
    # Find shortest path between all pairs of nodes
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
    
    return dist