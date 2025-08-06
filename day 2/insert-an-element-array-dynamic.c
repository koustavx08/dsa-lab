#include <stdio.h>
#include <stdlib.h>

void insertAtPosition(int *arr, int *size, int element, int position) {
    (*size)++;
    arr = realloc(arr, (*size) * sizeof(int));

    for (int i = *size - 1; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;

    printf("Array after insertion:\n");
    for (int i = 0; i < *size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, element, position;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to insert: ");
    scanf("%d", &element);
    printf("Enter position to insert (0-based index): ");
    scanf("%d", &position);

    if (position < 0 || position > n) {
        printf("Invalid position!\n");
    } else {
        insertAtPosition(arr, &n, element, position);
    }

    free(arr);
    return 0;
}
