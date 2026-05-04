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

Node* insert(Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

int lca(Node* root, int p, int q) {
    if (root == NULL) return -1;

    // Both nodes are in the right subtree
    if (p > root->data && q > root->data)
        return lca(root->right, p, q);

    // Both nodes are in the left subtree
    if (p < root->data && q < root->data)
        return lca(root->left, p, q);

    // Split point found — current node is the LCA
    return root->data;
}

int main() {
    int n;
    scanf("%d", &n);

    // Build BST by inserting elements one by one
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }

    // Read the two nodes whose LCA is to be found
    int p, q;
    scanf("%d %d", &p, &q);

    printf("%d\n", lca(root, p, q));

    return 0;
}
