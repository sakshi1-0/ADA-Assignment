28. Implement Prim's algorithm to find the minimum spanning tree of a given graph in flowchart.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5

// Function to find the vertex with the minimum key value
int min_key(int key[], int mst_set[]) {
    int min = INT_MAX, min_index;
    int v;
    for (v = 0; v < V; v++) {
        if (mst_set[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the minimum spanning tree
void print_mst(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    int i;
    for (i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

// Function to find the minimum spanning tree using Prim's algorithm
void prim_mst(int graph[V][V]) {
    int parent[V]; // Array to store the parent node of each vertex in the MST
    int key[V]; // Array to store the key value of each vertex
    int mst_set[V]; // Array to track whether each vertex is included in the MST
    int i;
    for (i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mst_set[i] = 0;
    }
    key[0] = 0; // Initialize the key value of the first vertex to 0
    parent[0] = -1; // Initialize the parent node of the first vertex to -1
    int count;
    for (count = 0; count < V-1; count++) {
        int u = min_key(key, mst_set); // Find the vertex with the minimum key value
        mst_set[u] = 1; // Add the vertex to the MST
        int v;
        for (v = 0; v < V; v++) {
            if (graph[u][v] && mst_set[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u; // Update the parent node of the vertex
                key[v] = graph[u][v]; // Update the key value of the vertex
            }
        }
    }
    print_mst(parent, graph); // Print the minimum spanning tree
}

// Driver code
int main() {
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};
    prim_mst(graph);
    return 0;
}