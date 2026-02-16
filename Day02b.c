#include <stdio.h>

int main() {
    int n;

    // Input number of days
    scanf("%d", &n);

    int prices[n];

    // Input prices
    for(int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    int minPrice = prices[0];
    int maxProfit = 0;

    for(int i = 1; i < n; i++) {
        
        // Update minimum price
        if(prices[i] < minPrice) {
            minPrice = prices[i];
        }
        
        // Calculate profit
        int profit = prices[i] - minPrice;
        
        // Update maximum profit
        if(profit > maxProfit) {
            maxProfit = profit;
        }
    }

    printf("%d", maxProfit);

    return 0;
}
