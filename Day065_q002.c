bool isCycle(int edges[][2], int E, int V) {
    int *par = (int*)malloc(V * sizeof(int));

    for (int i = 0; i < V; i++)
        par[i] = i;

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        // Find root of u
        while (par[u] != u) u = par[u];
        // Find root of v
        while (par[v] != v) v = par[v];

        if (u == v) {
            free(par);
            return true;
        }
        par[u] = v;
    }

    free(par);
    return false;
}
