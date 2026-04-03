int* adj[2001];
int adjSize[2001];
int visited[2001];
int recStack[2001];

int dfs(int node) {
    visited[node]  = 1;
    recStack[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor)) return 1;
        } else if (recStack[neighbor]) {
            // Cycle found → cannot finish courses
            return 1;
        }
    }

    recStack[node] = 0;
    return 0;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    // Initialize
    for (int i = 0; i < numCourses; i++) {
        adj[i]     = (int*)malloc(numCourses * sizeof(int));
        adjSize[i] = 0;
        visited[i] = 0;
        recStack[i]= 0;
    }

    // Build directed graph: b → a (b must be taken before a)
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        adj[b][adjSize[b]++] = a;
    }

    // Check for cycle in all components
    for (int i = 0; i < numCourses; i++)
        if (!visited[i])
            if (dfs(i)) return false;

    return true;
}
