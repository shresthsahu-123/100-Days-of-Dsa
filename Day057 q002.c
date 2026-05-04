void flatten(struct TreeNode* root) {
    if (root == NULL) return;

    // Flatten left and right subtrees first
    flatten(root->left);
    flatten(root->right);

    // Store right subtree
    struct TreeNode* rightSubtree = root->right;

    // Move left subtree to right
    root->right = root->left;
    root->left  = NULL;

    // Find the end of the new right (previously left) subtree
    struct TreeNode* curr = root;
    while (curr->right != NULL)
        curr = curr->right;

    // Attach original right subtree at the end
    curr->right = rightSubtree;
}
