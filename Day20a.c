#include <stdio.h>

int main() {
    int arr[] = {1, -1, 2, -2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int count = 0;

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            if(sum == 0)
                count++;
        }
    }

    printf("Count = %d\n", count);
    return 0;
}