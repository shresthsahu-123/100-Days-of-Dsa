#include <stdio.h>

int main() {
    int n, pos, x;
    
    // Input size of array
    scanf("%d", &n);
    
    int arr[n + 1];  // Create array with extra space for new element
    
    // Input array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input position (1-based)
    scanf("%d", &pos);
    
    // Input element to insert
    scanf("%d", &x);
    
    // Shift elements to the right
    for(int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    
    // Insert the element
    arr[pos - 1] = x;
    
    // Print updated array
    for(int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
