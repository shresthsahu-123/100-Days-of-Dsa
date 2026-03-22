#include <stdio.h>

int maxSubarraySum(int nums[], int n) {
    int maxSum = nums[0], curr = 0;

    for(int i = 0; i < n; i++) {
        curr += nums[i];
        if(curr > maxSum) maxSum = curr;
        if(curr < 0) curr = 0;
    }
    return maxSum;
}

int minSubarraySum(int nums[], int n) {
    int minSum = nums[0], curr = 0;

    for(int i = 0; i < n; i++) {
        curr += nums[i];
        if(curr < minSum) minSum = curr;
        if(curr > 0) curr = 0;
    }
    return minSum;
}

int maxCircularSum(int nums[], int n) {
    int totalSum = 0;

    for(int i = 0; i < n; i++) {
        totalSum += nums[i];
    }

    int maxSum = maxSubarraySum(nums, n);
    int minSum = minSubarraySum(nums, n);

    // Edge case: all elements are negative
    if(maxSum < 0)
        return maxSum;

    int circularSum = totalSum - minSum;

    return (maxSum > circularSum) ? maxSum : circularSum;
}

int main() {
    int nums[] = {5, -3, 5};
    int n = sizeof(nums)/sizeof(nums[0]);

    printf("Maximum Circular Subarray Sum = %d\n", maxCircularSum(nums, n));
    return 0;
}