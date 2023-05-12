 #Implement the PageRank algorithm to rank web pages in a network in Python.

import numpy as np

def pagerank(adj_matrix, damping_factor=0.85, epsilon=1e-6):
    """
    Computes the PageRank score for each node in a given graph.
    
    :param adj_matrix: numpy array representing the adjacency matrix of the graph
    :param damping_factor: the damping factor (default: 0.85)
    :param epsilon: the convergence threshold (default: 1e-6)
    :return: numpy array representing the PageRank score for each node
    """
    n = adj_matrix.shape[0]
    
    # normalize the adjacency matrix
    row_sums = np.sum(adj_matrix, axis=1)
    adj_matrix = adj_matrix / row_sums[:, np.newaxis]
    
    # initialize PageRank scores to 1/n
    pr = np.full(n, 1/n)
    
    # iteratively update PageRank scores
    while True:
        prev_pr = pr.copy()
        pr = (1 - damping_factor) / n + damping_factor * np.dot(adj_matrix, pr)
        if np.max(np.abs(pr - prev_pr)) < epsilon:
            break
    
    return pr