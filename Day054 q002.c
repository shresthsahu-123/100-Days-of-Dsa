int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (!root) return NULL;

    int** result = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int leftToRight = 1; // flag to alternate direction

    while (front < rear) {
        int size = rear - front;
        result[*returnSize] = (int*)malloc(size * sizeof(int));
        (*returnColumnSizes)[*returnSize] = size;

        for (int i = 0; i < size; i++) {
            struct TreeNode* curr = queue[front++];

            // Fill based on direction
            if (leftToRight)
                result[*returnSize][i] = curr->val;
            else
                result[*returnSize][size - 1 - i] = curr->val;

            if (curr->left)  queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }

        (*returnSize)++;
        leftToRight = !leftToRight; // flip direction
    }

    return result;
}
