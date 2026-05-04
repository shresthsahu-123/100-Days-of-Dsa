#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// DFS function to detect cycle
bool dfs(int node, int parent, int visited[], int adj[MAX][MAX], int n) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, node, visited, adj, n))
                    return true;
            }
            else if (i != parent) {
                // visited neighbor not parent → cycle
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    scanf("%d", &n);

    int adj[MAX][MAX];

    // Input adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int visited[MAX] = {0};
    bool hasCycle = false;

    // Check all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj, n)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
