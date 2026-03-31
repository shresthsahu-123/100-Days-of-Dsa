#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

void dfs(int node) {
    visited[node] = 1;
    printf("%d ", node);

    // Visit all unvisited neighbors
    for (int i = 0; i < n; i++)
        if (adj[node][i] == 1 && !visited[i])
            dfs(i);
}

int main() {
    int m;
    scanf("%d %d", &n, &m);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int s;
    scanf("%d", &s);

    // Initialize visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    dfs(s);
    printf("\n");

    return 0;
}
