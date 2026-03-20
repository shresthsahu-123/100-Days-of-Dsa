struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    // Base case: empty tree or node matches p or q
    if (root == NULL) return NULL;
    if (root->val == p->val || root->val == q->val) return root;

    // Search for LCA in left and right subtrees
    struct TreeNode* left  = lowestCommonAncestor(root->left,  p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // One node found in each subtree — current node is LCA
    if (left != NULL && right != NULL) return root;

    // Return whichever subtree found a node
    return left != NULL ? left : right;
}
