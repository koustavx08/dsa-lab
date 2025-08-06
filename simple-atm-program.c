#include <stdio.h>

int main() {
    int choice;
    float balance = 1000.00; // Initial balance
    float amount;

    do {
        // Menu display
        printf("\n----- ATM MENU -----\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        // Menu operations
        switch (choice) {
            case 1:
                printf("Your current balance is: ₹%.2f\n", balance);
                break;

            case 2:
                printf("Enter amount to deposit: ₹");
                scanf("%f", &amount);
                if (amount > 0) {
                    balance += amount;
                    printf("Deposit successful. New balance: ₹%.2f\n", balance);
                } else {
                    printf("Invalid deposit amount.\n");
                }
                break;

            case 3:
                printf("Enter amount to withdraw: ₹");
                scanf("%f", &amount);
                if (amount <= 0) {
                    printf("Invalid withdrawal amount.\n");
                } else if (amount > balance) {
                    printf("Insufficient balance!\n");
                } else {
                    balance -= amount;
                    printf("Withdrawal successful. New balance: ₹%.2f\n", balance);
                }
                break;

            case 4:
                printf("Thank you for using the ATM. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please select from 1 to 4.\n");
        }
    } while (choice != 4);

    return 0;
}
