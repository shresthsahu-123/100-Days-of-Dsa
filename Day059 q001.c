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

int findIndex(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++)
        if (inorder[i] == val) return i;
    return -1;
}

int postIndex;

Node* buildTree(int* inorder, int* postorder, int start, int end) {
    if (start > end) return NULL;

    // Current root is last element in postorder
    Node* root = newNode(postorder[postIndex--]);

    // Find root in inorder to split left and right subtrees
    int idx = findIndex(inorder, start, end, root->data);

    // Build right first (postorder goes right before left)
    root->right = buildTree(inorder, postorder, idx + 1, end);
    root->left  = buildTree(inorder, postorder, start, idx - 1);

    return root;
}

int first = 1;
void preorder(Node* root) {
    if (!root) return;
    if (!first) printf(" ");
    printf("%d", root->data);
    first = 0;
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);

    postIndex = n - 1; // start from last element of postorder

    Node* root = buildTree(inorder, postorder, 0, n - 1);

    preorder(root);
    printf("\n");

    return 0;
}
