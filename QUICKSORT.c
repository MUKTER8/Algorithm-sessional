#include<stdio.h>
int partition(int a[20], int low, int high);
void quicksort(int a[20], int low, int high);
void swap(int* a, int* b);

int main() {
    int a[20], n, i;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}

void swap(int* a, int* b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int a[20], int low, int high) {
    int pivot, i, j, leftwall;
    pivot = a[low];
    leftwall = low;
    for (i = (low + 1); i <= high; i++) {
        if (a[i] < pivot) {
            leftwall++;  
            swap(&a[i], &a[leftwall]);
           
        }
    }
    swap(&a[low], &a[leftwall]);
    return leftwall;
}

void quicksort(int a[20], int low, int high) {
    int pivot_location;

    if (low < high){
        pivot_location = partition(a, low, high);
        quicksort(a, low, pivot_location - 1);
        quicksort(a, pivot_location + 1, high);
    }
}
