#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[] = {1, 60, -10, 70, -80, 85};
    int n = sizeof(arr)/sizeof(arr[0]);

    int minSum = abs(arr[0] + arr[1]);
    int x = arr[0], y = arr[1];

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if(abs(sum) < minSum) {
                minSum = abs(sum);
                x = arr[i];
                y = arr[j];
            }
        }
    }

    printf("Pair: %d, %d\n", x, y);
    return 0;
}