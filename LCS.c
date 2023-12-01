#include <stdio.h>
#include <string.h>

// Function to find the length of the Longest Common Subsequence
int lcsLength(char X[], char Y[], int m, int n, char lcs[]) {
    int L[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }

    int index = L[m][n];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[--index] = X[--i];
            j--;
        } else {
            (L[i - 1][j] > L[i][j - 1]) ? i-- : j--;
        }
    }

    return L[m][n];
}

// Driver program to test the above function
int main() {
    int n1, n2, i;
    printf("Enter the size of X[]: ");
    scanf("%d", &n1);
    printf("Enter the size of Y[]: ");
    scanf("%d", &n2);

    char X[n1], Y[n2];
    
    printf("Input for X[]: ");
    for (i = 0; i < n1; i++) {
        scanf(" %c", &X[i]); // Use %c to read a character
    }

    printf("Input for Y[]: ");
    for (i = 0; i < n2; i++) {
        scanf(" %c", &Y[i]); // Use %c to read a character
    }

    char lcs[100];

    int length = lcsLength(X, Y, n1, n2, lcs);
    printf("LCS  :%s\n", lcs);
    printf("Length of LCS: %d\n", length);
    
    return 0;
}
