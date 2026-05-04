bool isMirror(struct TreeNode* left, struct TreeNode* right) {
    // Both NULL — symmetric
    if (left == NULL && right == NULL) return true;

    // One NULL, one not — not symmetric
    if (left == NULL || right == NULL) return false;

    // Values must match and subtrees must be mirrors
    return (left->val == right->val) &&
            isMirror(left->left,  right->right) &&
            isMirror(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}
