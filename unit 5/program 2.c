# Implement Depth First Search (DFS) algorithm to traverse a graph and find connected components in Python.

def dfs(graph, visited, node, component):
    visited[node] = True
    component.append(node)
    
    for neighbor in graph[node]:
        if not visited[neighbor]:
            dfs(graph, visited, neighbor, component)

def find_connected_components(graph):
    visited = {node: False for node in graph}
    components = []
    
    for node in graph:
        if not visited[node]:
            component = []
            dfs(graph, visited, node, component)
            components.append(component)
    
    return components