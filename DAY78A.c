#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    int graph[MAX][MAX];
    int visited[MAX] = {0};
    int i, j;

    printf("Enter number of vertices and edges:\n");
    scanf("%d %d", &n, &m);

    // Initialize graph with 0
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            graph[i][j] = 0;

    printf("Enter edges (u v w):\n");
    for(i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    visited[1] = 1; // start from vertex 1
    int edges = 0;
    int totalWeight = 0;

    while(edges < n - 1) {
        int min = INT_MAX;
        int x = -1, y = -1;

        for(i = 1; i <= n; i++) {
            if(visited[i]) {
                for(j = 1; j <= n; j++) {
                    if(!visited[j] && graph[i][j]) {
                        if(graph[i][j] < min) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        visited[y] = 1;
        totalWeight += min;
        edges++;

        printf("Edge selected: %d - %d (weight %d)\n", x, y, min);
    }

    printf("Total weight of MST: %d\n", totalWeight);

    return 0;
}