int postIndex;

int findIndex(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++)
        if (inorder[i] == val) return i;
    return -1;
}

struct TreeNode* build(int* inorder, int* postorder, int start, int end) {
    if (start > end) return NULL;

    // Current root is last element in postorder
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val   = postorder[postIndex--];
    root->left  = NULL;
    root->right = NULL;

    // Find root in inorder to split left and right subtrees
    int idx = findIndex(inorder, start, end, root->val);

    // Build right first then left (postorder goes right before left)
    root->right = build(inorder, postorder, idx + 1, end);
    root->left  = build(inorder, postorder, start, idx - 1);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    postIndex = postorderSize - 1;
    return build(inorder, postorder, 0, inorderSize - 1);
}
