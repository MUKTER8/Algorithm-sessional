#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 knapsack problem using dynamic programming
int knapsack(int capacity, int weights[], int values[], int n) {
    int dp[n + 1][capacity + 1];

    // Build the DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The maximum value will be in the bottom-right cell of the table
    return dp[n][capacity];
}

int main() {
    int n,i;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int values[n], weights[n];

    for ( i = 0; i < n; i++) {
        printf("Enter the value and weight of item %d: ", i + 1);
        scanf("%d %d", &values[i], &weights[i]);
    }


    int capacity;
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    int max_value = knapsack(capacity, weights, values, n);
    printf("Maximum value in the knapsack: %d\n", max_value);

    return 0;
}
