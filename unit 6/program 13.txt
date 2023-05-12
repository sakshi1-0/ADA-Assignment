# Develop an approximation algorithm for the Vertex Cover Problem

def vertex_cover(graph):
    cover = set()
    degrees = {v: len(graph[v]) for v in graph}

    while graph:
        vertex, degree = max(degrees.items(), key=lambda x: x[1])
        cover.add(vertex)
        for neighbor in graph[vertex]:
            degrees[neighbor] -= 1
        del degrees[vertex]
        del graph[vertex]

    return cover

# Evaluate its effectiveness on a variety of input graphs.
"""
To evaluate the effectiveness of the Modified Greedy Approximation Algorithm for the Vertex Cover Problem, 
we can test it on a variety of input graphs with different sizes and densities.
We can compare the size of the vertex cover found by the algorithm with 
the optimal vertex cover size obtained through exhaustive search or an exact algorithm for smaller graphs. 
We can also compare the running time of the algorithm with the running time of exact algorithms or other approximation algorithms.
"""
import networkx as nx
import time

# Generate random graphs of different sizes and densities
graphs = []
for n in [10, 50, 100]:
    for p in [0.1, 0.5, 0.9]:
        G = nx.erdos_renyi_graph(n, p)
        graphs.append(G)

# Test the algorithm on each graph
for i, G in enumerate(graphs):
    start_time = time.time()
    cover = vertex_cover(G)
    end_time = time.time()
    print(f"Graph {i+1}: |V|={G.number_of_nodes()}, |E|={G.number_of_edges()}")
    print(f"Vertex cover size: {len(cover)}")
    print(f"Running time: {end_time - start_time:.5f} seconds")