#include <stdio.h>
#include <stdlib.h>

void incrementAndDisplay(int *arr, int size) {
    printf("Array after incrementing each element:\n");
    for (int i = 0; i < size; i++) {
        arr[i]++;
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    incrementAndDisplay(arr, n);

    free(arr);
    return 0;
}
