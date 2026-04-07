#include <stdio.h>

// Restore Heap Up (for building max heap)
void restoreHeapUp(int h[], int index) {
    int val = h[index];

    while (index > 1 && h[index / 2] < val) {
        h[index] = h[index / 2];
        index = index / 2;
    }

    h[index] = val;
}

// Restore Heap Down (for heapify after deletion)
void restoreHeapDown(int h[], int index, int n) {
    int val = h[index];
    int j = 2 * index;

    while (j <= n) {
        // Select larger child
        if (j < n && h[j] < h[j + 1]) {
            j = j + 1;
        }

        if (val >= h[j]) {
            break;
        }

        h[j / 2] = h[j];
        j = 2 * j;
    }

    h[j / 2] = val;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int h[n + 1];  // 1-based indexing

    printf("Enter elements:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
    }

    // Build heap
    for (int i = 2; i <= n; i++) {
        restoreHeapUp(h, i);
    }

    // Heap sort
    int size = n;
    for (int i = n; i >= 2; i--) {
        // Swap root with last element
        int temp = h[1];
        h[1] = h[i];
        h[i] = temp;

        size--;
        restoreHeapDown(h, 1, size);
    }

    // Print sorted array
    printf("Sorted elements:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", h[i]);
    }

    return 0;
}