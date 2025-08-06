#include <stdio.h>
#include <stdlib.h>

void addAndSubtract(int **a, int **b, int rows, int cols) {
    printf("Addition of matrices:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", a[i][j] + b[i][j]);
        }
        printf("\n");
    }

    printf("Subtraction of matrices (A - B):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", a[i][j] - b[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Dynamic allocation of 2D arrays
    int **a = (int **)malloc(rows * sizeof(int *));
    int **b = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        a[i] = (int *)malloc(cols * sizeof(int));
        b[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &b[i][j]);

    addAndSubtract(a, b, rows, cols);

    // Free memory
    for (int i = 0; i < rows; i++) {
        free(a[i]);
        free(b[i]);
    }
    free(a);
    free(b);

    return 0;
}
