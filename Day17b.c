#include <stdio.h>

int maxSubArray(int nums[], int n) {
    int maxSum = nums[0];
    int currentSum = 0;

    for(int i = 0; i < n; i++) {
        currentSum += nums[i];

        if(currentSum > maxSum)
            maxSum = currentSum;

        if(currentSum < 0)
            currentSum = 0;
    }

    return maxSum;
}