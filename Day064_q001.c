#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Queue implementation
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

bool isEmpty() {
    return front == -1 || front > rear;
}

// BFS function
void bfs(int n, int adj[MAX][MAX], int s) {
    bool visited[MAX] = {false};

    enqueue(s);
    visited[s] = true;

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = true;
            }
        }
    }
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

    int s;
    scanf("%d", &s);

    bfs(n, adj, s);

    return 0;
}
