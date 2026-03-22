#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int matrix[][100], int m, int n, int* returnSize) {
    int *result = (int*)malloc(sizeof(int) * m * n);
    int k = 0;

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right) {

        // Left → Right
        for (int j = left; j <= right; j++) {
            result[k++] = matrix[top][j];
        }
        top++;

        // Top → Bottom
        for (int i = top; i <= bottom; i++) {
            result[k++] = matrix[i][right];
        }
        right--;

        // Right → Left
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                result[k++] = matrix[bottom][j];
            }
            bottom--;
        }

        // Bottom → Top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[k++] = matrix[i][left];
            }
            left++;
        }
    }

    *returnSize = k;
    return result;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[100][100];

    // Input
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int size;
    int *res = spiralOrder(matrix, m, n, &size);

    // Print result
    for(int i = 0; i < size; i++) {
        printf("%d ", res[i]);
    }

    free(res);

    return 0;
}