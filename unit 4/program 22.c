22. Implement Kruskal's algorithm to find the minimum spanning tree of a given graph in C

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000

// A structure to represent an edge in the graph
struct Edge {
    int u, v, weight;
};

// A structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// A structure to represent a graph
struct Graph {
    int V; // Number of vertices
    int E; // Number of edges
    struct Edge edges[MAX_EDGES]; // Array of edges
};

// Create a subset with one element
struct Subset makeSubset(int parent, int rank) {
    struct Subset subset = { parent, rank };
    return subset;
}

// Find the parent of a node in a subset (with path compression)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Union two subsets based on rank
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare function to sort edges based on weight
int compare(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*)a;
    struct Edge* edgeB = (struct Edge*)b;
    return edgeA->weight - edgeB->weight;
}

// Find the minimum spanning tree of the given graph using Kruskal's algorithm
void kruskal(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[MAX_NODES];
    int e = 0; // An index variable to keep track of edges added to result
    int i = 0; // An index variable to iterate over all the edges in the sorted order

    // Sort all the edges in non-decreasing order of their weight
    qsort(graph->edges, graph->E, sizeof(struct Edge), compare);

    // Allocate memory for subsets
    struct Subset subsets[MAX_NODES];
    for (int v = 0; v < V; v++) {
        subsets[v] = makeSubset(v, 0);
    }

    // Iterate through all the edges in sorted order
    while (e < V - 1 && i < graph->E) {
        // Get the next edge
        struct Edge nextEdge = graph->edges[i++];

        // Find the subsets of the endpoints of the edge
        int x = find(subsets, nextEdge.u);
        int y = find(subsets, nextEdge.v);

        // If including this edge doesn't cause a cycle, add it to the result
        if (x != y) {
            result[e++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    // Print the edges of the minimum spanning tree
    printf("Edges of the minimum spanning tree:\n");
    for (int i = 0; i < e; i++) {
        printf("(%d, %d) -> %d\n", result