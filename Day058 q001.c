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

// Find index of value in inorder array
int findIndex(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++)
        if (inorder[i] == val) return i;
    return -1;
}

int preIndex = 0;

Node* buildTree(int* preorder, int* inorder, int start, int end) {
    if (start > end) return NULL;

    // Current root is next element in preorder
    Node* root = newNode(preorder[preIndex++]);

    // Find root in inorder to split left and right subtrees
    int idx = findIndex(inorder, start, end, root->data);

    // Elements left of idx → left subtree
    // Elements right of idx → right subtree
    root->left  = buildTree(preorder, inorder, start, idx - 1);
    root->right = buildTree(preorder, inorder, idx + 1, end);

    return root;
}

int first = 1;
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    if (!first) printf(" ");
    printf("%d", root->data);
    first = 0;
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    Node* root = buildTree(preorder, inorder, 0, n - 1);

    postorder(root);
    printf("\n");

    return 0;
}
