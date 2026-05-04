struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL) return NULL;

    // Both nodes are in the right subtree
    if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);

    // Both nodes are in the left subtree
    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);

    // Split point found — current node is the LCA
    return root;
}
