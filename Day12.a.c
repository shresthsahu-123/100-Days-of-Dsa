#include <stdio.h>

int main() {
    int n;

    // Input size (square matrix)
    scanf("%d", &n);

    int matrix[n][n];

    // Input matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int isSymmetric = 1;

    // Check symmetry
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if(!isSymmetric) break;
    }

    // Output result
    if(isSymmetric)
        printf("Symmetric Matrix");
    else
        printf("Not Symmetric Matrix");

    return 0;
}