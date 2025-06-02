#include <stdio.h>

void printArray(int* arr, int size, const char* msg) {
    printf("%s: ", msg);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int low, int high, int* arr, int size) {
    int pivot = arr[low];
    int left = low + 1;
    int right = high;

    printf("\n-- Partitioning from index %d to %d --\n", low, high);
    printf("Initial pivot: arr[%d] = %d\n", low, pivot);
    printArray(arr, size, "Before partition");

    while (left <= right) {
        while (left <= high && arr[left] <= pivot) {
            printf("Moving left pointer: arr[%d] = %d <= pivot = %d\n", left, arr[left], pivot);
            left++;
        }
        while (arr[right] > pivot) {
            printf("Moving right pointer: arr[%d] = %d > pivot = %d\n", right, arr[right], pivot);
            right--;
        }
        if (left < right) {
            printf("Swapping arr[%d] = %d and arr[%d] = %d\n", left, arr[left], right, arr[right]);
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            printArray(arr, size, "After swap");
        }
    }

    // Final pivot placement
    printf("Placing pivot in correct position: swapping arr[%d] = %d and arr[%d] = %d\n", low, arr[low], right, arr[right]);
    int temp = arr[low];
    arr[low] = arr[right];
    arr[right] = temp;

    printArray(arr, size, "After pivot placement");
    printf("-- End of partition: pivot index = %d --\n", right);
    return right;
}

void quicksort(int low, int high, int* arr, int size) {
    if (low < high) {
        int p = partition(low, high, arr, size);
        quicksort(low, p - 1, arr, size);
        quicksort(p + 1, high, arr, size);
    }
}

int main() {
    int a[] = {2, 3, 8, 1, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);

    printArray(a, n, "Initial array");
    quicksort(0, n - 1, a, n);
    printArray(a, n, "\nSorted array");

    return 0;
}
