#include <stdio.h>

void productExceptSelf(int nums[], int n, int answer[]) {
    int prefix[n], suffix[n];

    // Prefix array
    prefix[0] = 1;
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    // Suffix array
    suffix[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    // Final answer
    for(int i = 0; i < n; i++) {
        answer[i] = prefix[i] * suffix[i];
    }
}

int main() {
    int nums[] = {1,2,3,4};
    int n = sizeof(nums)/sizeof(nums[0]);
    int answer[n];

    productExceptSelf(nums, n, answer);

    for(int i = 0; i < n; i++) {
        printf("%d ", answer[i]);
    }

    return 0;
}