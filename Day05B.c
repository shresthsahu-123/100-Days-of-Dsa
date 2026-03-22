#include <stdio.h>

void merge(int nums1[], int m, int nums2[], int n) {
    int i = m - 1;        // last element in nums1
    int j = n - 1;        // last element in nums2
    int k = m + n - 1;    // last position in nums1

    // Merge from back
    while(i >= 0 && j >= 0) {
        if(nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // If nums2 still has elements
    while(j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main() {
    int nums1[10] = {10, 20, 30, 50, 70, 0, 0, 0, 0}; // size = m+n
    int nums2[] = {15, 25, 40, 60};

    int m = 5, n = 4;

    merge(nums1, m, nums2, n);

    // Print result
    for(int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }

    return 0;
}