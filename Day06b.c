#include <stdio.h>

void moveZeroes(int nums[], int n) {
    int i = 0; // position for next non-zero

    // Step 1: Move non-zero elements forward
    for(int j = 0; j < n; j++) {
        if(nums[j] != 0) {
            nums[i] = nums[j];
            i++;
        }
    }

    // Step 2: Fill remaining with zeros
    while(i < n) {
        nums[i] = 0;
        i++;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    moveZeroes(nums, n);

    // Print result
    for(int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}