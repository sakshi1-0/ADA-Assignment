# Implement the Prim's algorithm to find the minimum spanning tree of a given graph in Python.

import heapq

def prim(graph, start):
    # Initialize variables
    mst = []
    visited = set([start])
    edges = [(weight, start, to) for to, weight in graph[start].items()]
    heapq.heapify(edges)
    
    # Loop until all nodes are visited or no more edges left
    while edges:
        # Get the edge with the smallest weight
        weight, frm, to = heapq.heappop(edges)
        if to not in visited:
            # Add the edge to the minimum spanning tree
            mst.append((frm, to, weight))
            visited.add(to)
            
            # Add new edges to the heap
            for to_next, weight_next in graph[to].items():
                if to_next not in visited:
                    heapq.heappush(edges, (weight_next, to, to_next))
    
    return mst