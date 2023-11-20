#include <stdio.h>

#define MAX 100

int visited[MAX];
int adjMatrix[MAX][MAX];

void initialize(int vertices) {
    int i, j;
    for (i = 0; i < vertices; ++i) {
        visited[i] = 0;
        for (j = 0; j < vertices; ++j) {
            adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(int src, int dest) {
    adjMatrix[src][dest] = 1;
    adjMatrix[dest][src] = 1; // assuming an undirected graph
}

void DFS(int vertex, int vertices) {
    visited[vertex] = 1;

    for (int i = 0; i < vertices; ++i) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(i, vertices);
        }
    }
}

int isConnected(int vertices) {
    int startVertex = 0;

    // Perform DFS starting from the first vertex
    DFS(startVertex, vertices);

    // Check if all vertices are visited
    for (int i = 0; i < vertices; ++i) {
        if (!visited[i]) {
            return 0; // Graph is not connected
        }
    }

    return 1; // Graph is connected
}

int main() {
    int vertices, edges, i, src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    initialize(vertices);

    for (i = 0; i < edges; ++i) {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    if (isConnected(vertices)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    return 0;
}
