void dfs(int** image, int sr, int sc, int rows, int cols, int oldColor, int newColor) {
    // Out of bounds or different color — stop
    if (sr < 0 || sr >= rows || sc < 0 || sc >= cols) return;
    if (image[sr][sc] != oldColor) return;

    // Change color
    image[sr][sc] = newColor;

    // Explore all 4 directions
    dfs(image, sr - 1, sc, rows, cols, oldColor, newColor); // up
    dfs(image, sr + 1, sc, rows, cols, oldColor, newColor); // down
    dfs(image, sr, sc - 1, rows, cols, oldColor, newColor); // left
    dfs(image, sr, sc + 1, rows, cols, oldColor, newColor); // right
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    int oldColor = image[sr][sc];

    // Only fill if old color is different from new color
    if (oldColor != color)
        dfs(image, sr, sc, imageSize, imageColSize[0], oldColor, color);

    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;

    return image;
}
