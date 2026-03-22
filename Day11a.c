#include <stdio.h>

int main() {
    int r, c;

    // Input dimensions
    scanf("%d %d", &r, &c);

    int A[r][c], B[r][c], Sum[r][c];

    // Input matrix A
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Input matrix B
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Addition
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            Sum[i][j] = A[i][j] + B[i][j];
        }
    }

    // Print result
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("%d ", Sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}