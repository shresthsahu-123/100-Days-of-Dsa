#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Queue node to store tree node with its horizontal distance
typedef struct QNode {
    Node* node;
    int hd; // horizontal distance from root
} QNode;

Node* newNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

Node* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node* queue[n];
    int front = 0, rear = 0;

    Node* root = newNode(arr[0]);
    queue[rear++] = root;
    int i = 1;

    while (front < rear && i < n) {
        Node* curr = queue[front++];

        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}

#define MAX 1000

int hdArr[MAX];    // horizontal distances
int valArr[MAX];   // node values
int size = 0;

void bfs(Node* root) {
    QNode queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = (QNode){root, 0};

    while (front < rear) {
        QNode curr = queue[front++];
        Node* node = curr.node;
        int hd = curr.hd;

        // Store node value with its horizontal distance
        hdArr[size] = hd;
        valArr[size] = node->data;
        size++;

        if (node->left)
            queue[rear++] = (QNode){node->left, hd - 1};
        if (node->right)
            queue[rear++] = (QNode){node->right, hd + 1};
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);
    bfs(root);

    // Find min and max horizontal distance
    int minHD = 0, maxHD = 0;
    for (int i = 0; i < size; i++) {
        if (hdArr[i] < minHD) minHD = hdArr[i];
        if (hdArr[i] > maxHD) maxHD = hdArr[i];
    }

    // Print nodes column by column
    for (int hd = minHD; hd <= maxHD; hd++) {
        int first = 1;
        for (int i = 0; i < size; i++) {
            if (hdArr[i] == hd) {
                if (!first) printf(" ");
                printf("%d", valArr[i]);
                first = 0;
            }
        }
        printf("\n");
    }

    return 0;
}
