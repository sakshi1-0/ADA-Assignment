# Implement Dijkstra's algorithm to find the shortest path between two nodes in a weighted graph in C or Python.

import heapq

def dijkstra(graph, start, end):
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    visited = {}
    pq = [(0, start)]
    
    while pq:
        (dist, current_node) = heapq.heappop(pq)
        
        if current_node == end:
            return distances[end]
        
        if current_node in visited:
            continue
        
        visited[current_node] = True
        
        for neighbor, weight in graph[current_node].items():
            distance = distances[current_node] + weight
            
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(pq, (distance, neighbor))
    
    return distances[end] if end in distances else -1