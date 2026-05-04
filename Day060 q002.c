// States:
// 0 = not covered
// 1 = has camera
// 2 = covered (no camera)

int cameras;

int dfs(struct TreeNode* root) {
    if (root == NULL) return 2; // NULL nodes are covered by default

    int left  = dfs(root->left);
    int right = dfs(root->right);

    // If any child is not covered → place camera here
    if (left == 0 || right == 0) {
        cameras++;
        return 1;
    }

    // If any child has camera → this node is covered
    if (left == 1 || right == 1)
        return 2;

    // Both children are covered but no camera → not covered
    return 0;
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0;

    // If root itself is not covered → place camera at root
    if (dfs(root) == 0)
        cameras++;

    return cameras;
}
