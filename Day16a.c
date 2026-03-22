#include <stdio.h>

int main() {
    int arr[] = {1, 2, 2, 3, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int freq[100] = {0}; // assuming elements are < 100

    // Count frequencies
    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Print frequencies
    for(int i = 0; i < 100; i++) {
        if(freq[i] > 0) {
            printf("%d occurs %d times\n", i, freq[i]);
        }
    }

    return 0;
}