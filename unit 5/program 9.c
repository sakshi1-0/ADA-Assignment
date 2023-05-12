# Implement the Girvan-Newman algorithm to find communities in a social network in Python.

import networkx as nx

def girvan_newman(G):
    # Get the initial communities
    c = list(nx.connected_components(G))
    # Keep track of the modularity score
    max_modularity = -1
    # Initialize the current communities
    current_c = c
    while True:
        # Get the betweenness centrality of all edges
        centrality = nx.edge_betweenness_centrality(G)
        # Sort edges in descending order of betweenness centrality
        sorted_edges = sorted(centrality.items(), key=lambda x: x[1], reverse=True)
        # Remove the edge with the highest betweenness centrality
        G.remove_edge(*sorted_edges[0][0])
        # Get the new communities
        new_c = list(nx.connected_components(G))
        # Compute the modularity score
        modularity = nx.algorithms.community.modularity(G, new_c)
        # Update the max modularity score and communities if necessary
        if modularity > max_modularity:
            max_modularity = modularity
            current_c = new_c
        # Stop if the number of communities is the same as before the removal
        if len(new_c) == len(c):
            break
        c = new_c
    return current_c