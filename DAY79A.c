#include <stdio.h>
#include <limits.h>

#define MAX 100

int n, m;
int graph[MAX][MAX];

// Find vertex with minimum distance
int minDistance(int dist[], int visited[]) {
int min = INT_MAX, min_index = -1;


for (int i = 1; i <= n; i++) {
    if (!visited[i] && dist[i] <= min) {
        min = dist[i];
        min_index = i;
    }
}
return min_index;


}

// Dijkstra Algorithm
void dijkstra(int source) {
int dist[MAX], visited[MAX];


for (int i = 1; i <= n; i++) {
    dist[i] = INT_MAX;
    visited[i] = 0;
}

dist[source] = 0;

for (int count = 1; count <= n - 1; count++) {
    int u = minDistance(dist, visited);
    visited[u] = 1;

    for (int v = 1; v <= n; v++) {
        if (!visited[v] && graph[u][v] &&
            dist[u] != INT_MAX &&
            dist[u] + graph[u][v] < dist[v]) {
            
            dist[v] = dist[u] + graph[u][v];
        }
    }
}

// Print result
for (int i = 1; i <= n; i++) {
    printf("%d ", dist[i]);
}


}

int main() {
int u, v, w, source;


printf("Enter number of vertices and edges: ");
scanf("%d %d", &n, &m);

// Initialize graph
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        graph[i][j] = 0;

printf("Enter edges (u v w):\n");
for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &u, &v, &w);
    graph[u][v] = w;
    graph[v][u] = w; // remove if directed graph
}

printf("Enter source: ");
scanf("%d", &source);

dijkstra(source);

return 0;

}
