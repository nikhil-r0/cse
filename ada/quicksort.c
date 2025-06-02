#include <stdio.h>

int partition(int low, int high, int* arr) {
    int pivot = arr[low];
    int left = low + 1;
    int right = high;

    while (left <= right) {
        while (left <= high && arr[left] <= pivot)
            left++;
        while (arr[right] > pivot)
            right--;
        if (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }

    // Swap pivot to its correct position
    int temp = arr[low];
    arr[low] = arr[right];
    arr[right] = temp;

    return right;
}

void quicksort(int low, int high, int* arr) {
    if (low < high) {
        int p = partition(low, high, arr);
        quicksort(low, p - 1, arr);
        quicksort(p + 1, high, arr);
    }
}

int main() {
    int a[] = {2, 3, 8, 1, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    quicksort(0, n - 1, a);

    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");

    return 0;
}
