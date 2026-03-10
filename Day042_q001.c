#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int queue[n], stack[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    // Queue -> Stack (reverse order)
    int top = -1;
    for (int i = 0; i < n; i++)
        stack[++top] = queue[i];

    // Stack -> Print (reversed)
    while (top >= 0) {
        printf("%d", stack[top--]);
        if (top >= 0) printf(" ");
    }
    printf("\n");

    return 0;
}
