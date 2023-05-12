#Implement Breadth First Search (BFS) algorithm to find the shortest path between two nodes in a graph in Python.



from collections import deque

def bfs_shortest_path(graph, start, end):
    # Keep track of visited nodes and their parent nodes
    visited = {start: None}
    # Queue to keep track of nodes to be visited next
    queue = deque([start])

    # Continue until all nodes have been visited or the end node has been found
    while queue:
        current = queue.popleft()
        if current == end:
            # End node has been found, construct path and return
            path = []
            while current is not None:
                path.append(current)
                current = visited[current]
            return list(reversed(path))
        
        # Visit all neighbors of the current node
        for neighbor in graph[current]:
            if neighbor not in visited:
                visited[neighbor] = current
                queue.append(neighbor)
    
    # End node was not found, return None
    return None