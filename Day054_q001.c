#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

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

void zigzag(Node* root) {
    if (!root) return;

    Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int leftToRight = 1; // flag to alternate direction
    int firstOverall = 1;

    while (front < rear) {
        int size = rear - front;
        int level[size];

        // Store current level nodes in level array
        for (int i = 0; i < size; i++) {
            Node* curr = queue[front++];

            // Fill level array based on direction
            if (leftToRight)
                level[i] = curr->data;
            else
                level[size - 1 - i] = curr->data;

            if (curr->left)  queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }

        // Print current level
        for (int i = 0; i < size; i++) {
            if (!firstOverall) printf(" ");
            printf("%d", level[i]);
            firstOverall = 0;
        }

        // Flip direction for next level
        leftToRight = !leftToRight;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);
    zigzag(root);

    return 0;
}
