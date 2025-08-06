#include <stdio.h>

// Function to calculate factorial using pointer
void factorial(int num, long long *result) {
    *result = 1;
    for (int i = 1; i <= num; i++) {
        *result = *result * i;
    }
}

int main() {
    int n;
    long long fact;
    
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        factorial(n, &fact);
        printf("Factorial of %d is: %lld\n", n, fact);
    }

    return 0;
}
