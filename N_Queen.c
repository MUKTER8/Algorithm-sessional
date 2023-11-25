#include <stdio.h>
#include <math.h>
#include<stdlib.h>

int a[30], count = 0;

int place(int pos) {
    int i;
    for (i = 0; i < pos; i++) {
        if ((a[i] == a[pos]) || (abs(a[i] - a[pos]) == abs(i - pos)))
            return 0;
    }
    return 1;
}

void print_sol(int n) {
    int i, j;
    count++;
    printf("\nCombination  %d : \n", count);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (a[i] == j) {
                printf("Q\t");
            } else {
                printf("*\t");
            }
        }
        printf("\n");
    }
}

void queen(int n, int k) {
    int i;
    for (i = 0; i < n; i++) {
        a[k] = i;
        if (place(k)) {
            if (k == n - 1) {
                print_sol(n);
            } else {
                queen(n, k + 1);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the N :");
    scanf("%d", &n);
    printf("Total Queen : %d",n);
    queen(n, 0);
    printf("Total combinations : %d\n", count);

    return 0;
}
