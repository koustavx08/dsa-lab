#include <stdio.h>

// Function to swap two numbers using pointers (call by reference)
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y;

    printf("Enter two numbers:\n");
    printf("x = ");
    scanf("%d", &x);
    printf("y = ");
    scanf("%d", &y);

    printf("\nBefore swapping: x = %d, y = %d\n", x, y);

    // Call the swap function
    swap(&x, &y);

    printf("After swapping : x = %d, y = %d\n", x, y);

    return 0;
}
