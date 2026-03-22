#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int matrix[n][n];
    int sum = 0;

    // Input matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Sum of primary diagonal
    for(int i = 0; i < n; i++) {
        sum += matrix[i][i];
    }

    printf("%d", sum);

    return 0;
}