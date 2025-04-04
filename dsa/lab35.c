#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX]; // Adjacency matrix
int visited[MAX];  // Visited array
int n;             // Number of vertices

// Function to perform DFS
void DFS(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

// Algorithm to implement DFS
/*
1. Start from the given starting vertex.
2. Mark the current vertex as visited.
3. Print the current vertex.
4. Recursively visit all adjacent vertices that are not visited.
*/

int main() {
    int edges, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // For undirected graph
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    printf("Depth-First Search starting from vertex %d:\n", startVertex);
    DFS(startVertex);

    return 0;
}