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

Node* lca(Node* root, int p, int q) {
    // Base case: empty tree or node matches p or q
    if (root == NULL) return NULL;
    if (root->data == p || root->data == q) return root;

    // Search for LCA in left and right subtrees
    Node* left  = lca(root->left,  p, q);
    Node* right = lca(root->right, p, q);

    // One node found in each subtree — current node is LCA
    if (left != NULL && right != NULL) return root;

    // Return whichever subtree found a node
    return left != NULL ? left : right;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);

    int p, q;
    scanf("%d %d", &p, &q);

    Node* result = lca(root, p, q);
    printf("%d\n", result->data);

    return 0;
}
