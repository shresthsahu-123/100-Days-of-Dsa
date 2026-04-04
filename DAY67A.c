#include <stdio.h>

#define MAX 100

int stack[MAX], top = -1;
int visited[MAX];

// Push into stack
void push(int x) {
    stack[++top] = x;
}

// DFS function
void dfs(int v, int n, int adj[MAX][MAX]) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i, n, adj);
        }
    }

    // Push after visiting all neighbors
    push(v);
}

int main() {
    int n, i, j;
    int adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize visited
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Call DFS for all nodes
    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n, adj);
        }
    }

    // Print topological order (reverse of stack)
    printf("Topological Order:\n");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}