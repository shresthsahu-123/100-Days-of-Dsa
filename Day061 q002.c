void dfs(int** grid, int* visited, int node, int n) {
    visited[node] = 1;

    // Visit all directly connected unvisited cities
    for (int j = 0; j < n; j++)
        if (grid[node][j] == 1 && !visited[j])
            dfs(grid, visited, j, n);
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int n = isConnectedSize;
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;

    int provinces = 0;

    for (int i = 0; i < n; i++) {
        // Each unvisited node starts a new province
        if (!visited[i]) {
            dfs(isConnected, visited, i, n);
            provinces++;
        }
    }

    return provinces;
}
