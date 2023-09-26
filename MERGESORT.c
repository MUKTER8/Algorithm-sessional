#include <stdio.h>

void merge(int a[20], int p, int q, int r);
void mergesort(int a[20], int p, int r);

int main() {
    int i, n, a[20];
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    mergesort(a, 0, n - 1);
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}

void merge(int a[20], int p, int q, int r) {
    int i, j, k, n1, n2;
    n1 = q - p + 1;
    n2 = r - q;
    int l[n1], m[n2];
    for (i = 0; i < n1; i++) {
        l[i] = a[p + i];
    }
    for (j = 0; j < n2; j++) {
        m[j] = a[q + j + 1];
    }
    i = 0;
    j = 0;
   for(k=p;k<=r;k++){
    if(l[i]<=m[j]){
        a[k]=l[i];
        i++;
    }
    else{
        a[k]=m[j];
        j++;
    }
   }
}

void mergesort(int a[20], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergesort(a, p, q);
        mergesort(a, q + 1, r);
        merge(a, p, q, r);
    }
}
