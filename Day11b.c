#include <stdio.h>

int main() {
    int r, c;

    // Input dimensions
    scanf("%d %d", &r, &c);

    int matrix[r][c];
    int transpose[c][r];

    // Input matrix
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Transpose logic
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Print transpose
    for(int i = 0; i < c; i++) {
        for(int j = 0; j < r; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}