#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[n][n];

    // Initialize matrix with 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    // Read edges and fill matrix
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;        // directed edge u → v
        adj[v][u] = 1;        // remove this line for directed graph
    }

    // Print adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j != 0) printf(" ");
            printf("%d", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
