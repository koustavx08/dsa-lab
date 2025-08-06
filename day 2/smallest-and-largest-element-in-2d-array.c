#include <stdio.h>
#include <stdlib.h>

void findMinMax(int **arr, int rows, int cols, int *min, int *max) {
    *min = *max = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] < *min)
                *min = arr[i][j];
            if (arr[i][j] > *max)
                *max = arr[i][j];
        }
    }
}

int main() {
    int rows, cols, min, max;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter elements of the 2D array:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &arr[i][j]);

    findMinMax(arr, rows, cols, &min, &max);

    printf("Smallest element: %d\n", min);
    printf("Largest element : %d\n", max);

    // Free memory
    for (int i = 0; i < rows; i++)
        free(arr[i]);
    free(arr);

    return 0;
}
