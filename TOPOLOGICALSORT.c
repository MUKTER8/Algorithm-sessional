#include <stdio.h>
#define MAX 50
int n,a[MAX][MAX],indegree[MAX],i,j;
char nodes[20];

void find_indegree() {
    for ( i = 0; i < n; i++) {
        indegree[i] = 0;
        for ( j = 0; j < n; j++) {
               indegree[i] += a[j][i];
        }
    }
}

void topo() {
    int t[MAX],s[MAX], top = -1,k = 0,u,v;

    find_indegree();

    for (i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            s[++top] = i;
        }
    }

    while (top != -1) {
        u = s[top--];
        t[k++] = u;

        for (v = 0; v < n; v++) {
            if (a[u][v]==1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    s[++top] = v;
                }
            }
        }
    }

    printf("Topological order: ");
    for ( i = 0; i < n; i++) {
        printf("%c ", nodes[t[i]]);  
    }
    printf("\n");
}

int main() {
    printf("Enter the number of nodes :");
     scanf("%d", &n);

    printf("Enter the node (A, B, C,..OR 1 ,2 ....):\n");
    for (i = 0; i < n; i++) {
        scanf(" %c", &nodes[i]);
    }

    printf("Enter the adjacency matrix:\n");
    for ( i = 0; i < n; i++) {
        printf("Row %d: ", i+1);
        for ( j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    topo();
    return 0;
}
