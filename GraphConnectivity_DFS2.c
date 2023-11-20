#include <stdio.h>

#define MAX 100

int visited[MAX];

void initialize(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
}

void DFS(int graph[MAX][MAX], int n, int vertex) {
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(graph, n, i);
        }
    }
}

int isConnected(int graph[MAX][MAX], int n) {
    initialize(n);

    // Start DFS from the first vertex
    DFS(graph, n, 0);

    // Check if all vertices are visited
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return 0; // Graph is not connected
        }
    }

    return 1; // Graph is connected
}

void printGraph(int graph[MAX][MAX], int n) {
    printf("Graph Edges:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                printf("%d -> %d\n", i + 1, j + 1);
            }
        }
    }
}

int main() {
    int n; // Number of vertices in the graph
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[MAX][MAX];

    // Input the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (isConnected(graph, n)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    printGraph(graph, n);

    return 0;
}
