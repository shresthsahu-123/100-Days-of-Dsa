#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int adjSize[MAX];
int visited[MAX];
int recStack[MAX]; // recursion stack to track current DFS path
int n;

int dfs(int node) {
    visited[node]  = 1;
    recStack[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor)) return 1;
        } else if (recStack[neighbor]) {
            // Visited and in current path → cycle
            return 1;
        }
    }

    // Remove from recursion stack before backtracking
    recStack[node] = 0;
    return 0;
}

int main() {
    int m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) adjSize[i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v; // directed edge u → v
    }

    for (int i = 0; i < n; i++) {
        visited[i]  = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < n; i++)
        if (!visited[i])
            if (dfs(i)) {
                printf("YES\n");
                return 0;
            }

    printf("NO\n");
    return 0;
}
