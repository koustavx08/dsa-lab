#include <stdio.h>

int main() {
    int num1, num2;
    int *ptr1, *ptr2;

    printf("Enter two integers:\n");
    scanf("%d %d", &num1, &num2);

    // Assign addresses to pointers
    ptr1 = &num1;
    ptr2 = &num2;

    // Perform arithmetic operations using pointers
    printf("\n--- Arithmetic Operations ---\n");
    printf("Addition       = %d\n", (*ptr1) + (*ptr2));
    printf("Subtraction    = %d\n", (*ptr1) - (*ptr2));
    printf("Multiplication = %d\n", (*ptr1) * (*ptr2));

    if (*ptr2 != 0) {
        printf("Division       = %.2f\n", (float)(*ptr1) / (*ptr2));
    } else {
        printf("Division       = Undefined (division by zero)\n");
    }

    return 0;
}
