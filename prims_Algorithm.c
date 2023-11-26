#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define max_vertices 10
int i, j, n;
int minKey(int key[], bool mst[], int V) 
{
 int min = INT_MAX, min_index;
 for (int v = 0; v < V; v++) 
 {
 if (!mst[v] && key[v] < min) 
 {
 min = key[v];
 min_index = v;
 }
 }
 return min_index;
}
void printMST(int parent[], int graph[max_vertices][max_vertices], int V) 
{
 printf("Edge \tWeight\n");
 // Loop through all vertices starting from the second (1-indexed)
 for (int i = 1; i < V; i++) 
 {
 printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
 }
}
void primMST(int graph[max_vertices][max_vertices], int V) 
{
 int parent[V], key[V];
 bool mst[V];
 for (int i = 0; i < V; i++) 
 {
 key[i] = INT_MAX;
 mst[i] = false;
 }
 key[0] = 0;
 parent[0] = -1;
 for (int count = 0; count < V - 1; count++) 
 {
 int u = minKey(key, mst, V);
 mst[u] = true;
 for (int v = 0; v < V; v++) 
 {
 if (graph[u][v] && !mst[v] && graph[u][v] < key[v]) 
 {
 parent[v] = u;
 key[v] = graph[u][v];
 }
 }
 }
 printMST(parent, graph, V);
}
int main() {
 printf("Enter the number of vertices (max %d): ", max_vertices);
 scanf("%d", &n);
 int graph[max_vertices][max_vertices];
 printf("Enter the weighted graph adjacency matrix (enter 0 if there is no edge):\n");
 for (i = 0; i < n; i++) 
 {
 for (j = 0; j < n; j++) 
 {
 scanf("%d", &graph[i][j]);
 }
 }
 primMST(graph, n);
 return 0;
}