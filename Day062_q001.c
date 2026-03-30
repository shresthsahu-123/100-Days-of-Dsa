#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a new adjacency list node
Node* newNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = val;
    n->next = NULL;
    return n;
}

// Add edge to adjacency list
void addEdge(Node** adj, int u, int v) {
    // Add v to u's list
    Node* node = newNode(v);
    node->next = adj[u];
    adj[u] = node;

    // Add u to v's list (remove for directed graph)
    node = newNode(u);
    node->next = adj[v];
    adj[v] = node;
}

void printList(Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize adjacency list
    Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    // Read and add edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    // Print adjacency list
    for (int i = 0; i < n; i++) {
        printf("%d -> ", i);
        printList(adj[i]);
    }

    return 0;
}
