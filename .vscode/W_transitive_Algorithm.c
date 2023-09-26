#include <stdio.h>
#define MAX 10

void transitive_closure(int adj[MAX][MAX], int t[MAX][MAX], int n) {
    int i, j, k;

    // Initialize the transitive closure matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                t[i][j] = 1;
            } else {
                t[i][j] = 0;
            }
        }
    }

    // Perform transitive closure computation
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                t[i][j] = t[i][j] || (t[i][k] && t[k][j]);
            }
        }
    }
}

int main() {
    int n,i,j;
    int adj[MAX][MAX], t[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for ( i = 0;i < n;i++) {
        for ( j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    transitive_closure(adj, t, n);

    printf("Transitive Closure Matrix:\n");
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {           
             printf("%d ", t[i][j]);
        }
        printf("\n");
    }

    return 0;
}
