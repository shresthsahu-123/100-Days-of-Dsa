#include <stdio.h>

int main() {
    int size;

    // Read size of array (n-1 elements)
    scanf("%d", &size);

    int arr[size];
    long long array_sum = 0;

    // Read array elements
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        array_sum += arr[i];
    }

    // Actual range is 1 to n
    long long n = size + 1;

    // Sum of first n natural numbers
    long long total_sum = n * (n + 1) / 2;

    // Missing number
    long long missing = total_sum - array_sum;

    printf("%lld\n", missing);

    return 0;
}