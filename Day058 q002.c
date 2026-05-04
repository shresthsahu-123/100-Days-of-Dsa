int preIndex = 0;

int findIndex(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++)
        if (inorder[i] == val) return i;
    return -1;
}

struct TreeNode* build(int* preorder, int* inorder, int start, int end) {
    if (start > end) return NULL;

    // Current root is next element in preorder
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val   = preorder[preIndex++];
    root->left  = NULL;
    root->right = NULL;

    // Find root in inorder to split left and right subtrees
    int idx = findIndex(inorder, start, end, root->val);

    // Build left then right subtree
    root->left  = build(preorder, inorder, start, idx - 1);
    root->right = build(preorder, inorder, idx + 1, end);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    preIndex = 0;
    return build(preorder, inorder, 0, inorderSize - 1);
}
