#include <stdio.h>
#include <stdlib.h>

// comparator for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int* intersect(int nums1[], int m, int nums2[], int n, int* returnSize) {
    // Sort both arrays
    qsort(nums1, m, sizeof(int), compare);
    qsort(nums2, n, sizeof(int), compare);

    int i = 0, j = 0, k = 0;

    // Allocate max possible size
    int *result = (int*)malloc(sizeof(int) * (m < n ? m : n));

    while (i < m && j < n) {
        if (nums1[i] == nums2[j]) {
            result[k++] = nums1[i];
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j]) {
            i++;
        }
        else {
            j++;
        }
    }

    *returnSize = k;
    return result;
}

int main() {
    int nums1[] = {1,2,2,1};
    int nums2[] = {2,2};

    int m = 4, n = 2;
    int size;

    int *res = intersect(nums1, m, nums2, n, &size);

    for (int i = 0; i < size; i++) {
        printf("%d ", res[i]);
    }

    free(res);
    return 0;
}