23. Implement the Dijkstra algorithm to find the shortest path between two vertices in a graph in C

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000

// A structure to represent a graph
struct Graph {
    int V; // Number of vertices
    int E; // Number of edges
    int edges[MAX_NODES][MAX_NODES]; // Adjacency matrix
};

// Find the vertex with minimum distance value (not yet included in the shortest path tree)
int minDistance(int dist[], int visited[], int V) {
    int minDist = INT_MAX;
    int minVertex = -1;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= minDist) {
            minDist = dist[v];
            minVertex = v;
        }
    }
    return minVertex;
}

// Print the shortest path from the source to the destination
void printPath(int parent[], int destination) {
    if (parent[destination] == -1) {
        printf("%d ", destination);
        return;
    }
    printPath(parent, parent[destination]);
    printf("%d ", destination);
}

// Find the shortest path from the source to the destination using Dijkstra's algorithm
void dijkstra(struct Graph* graph, int source, int destination) {
    int V = graph->V;
    int dist[MAX_NODES]; // Array to store the shortest distance from source to i
    int visited[MAX_NODES]; // Array to mark vertices as visited or not visited
    int parent[MAX_NODES]; // Array to store the parent of each vertex in the shortest path tree

    // Initialize dist[], visited[], and parent[]
    for (int v = 0; v < V; v++) {
        dist[v] = INT_MAX;
        visited[v] = 0;
        parent[v] = -1;
    }

    // Distance from source to itself is always 0
    dist[source] = 0;

    // Find the shortest path for all vertices
    for (int i = 0; i < V - 1; i++) {
        // Choose the vertex with minimum distance value (not yet included in the shortest path tree)
        int u = minDistance(dist, visited, V);

        // Mark the chosen vertex as visited
        visited[u] = 1;

        // Update the distance of adjacent vertices of the chosen vertex
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph->edges[u][v] && dist[u] != INT_MAX && dist[u] + graph->edges[u][v] < dist[v]) {
                dist[v] = dist[u] + graph->edges[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the shortest path from the source to the destination
    printf("Shortest path from %d to %d: ", source, destination);
    printPath(parent, destination);
    printf("\n");

    // Print the distance from the source to all vertices
    printf("Distance from source to all vertices:\n");
    for (int v = 0; v < V; v++) {
        printf("%d -> %d: %d\n", source, v, dist[v]);
    }
}

int main() {
    struct Graph graph = {
        .V = 5,
        .E = 7,
        .edges = {
            {0, 4, 0, 0, 3},
            {4, 0, 1,