#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int *arr;    // Pointer to dynamically allocate array
    int top;     // Index of the top element
    int capacity; // Maximum size of stack
};

// Function to create a stack
struct Stack *createStack(int capacity) {
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));
    stack -> capacity = capacity;
    stack -> top = -1;
    stack -> arr = (int *) malloc(stack -> capacity * sizeof(int));
    return stack;
}


int isFull(struct Stack *stack) {
    return stack -> top == stack -> capacity - 1;
}


int isEmpty(struct Stack *stack) {
    return stack -> top == -1;
}


void push(struct Stack *stack, int val) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", val);
        return;
    }
    stack -> arr[++stack -> top] = val;
    printf("%d pushed to stack\n", val);
}


void pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Nothing to pop\n");
        return;
    }
    printf("%d popped from stack\n", stack -> arr[stack -> top--]);
}

void peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is %d\n", stack->arr[stack->top]);
}


void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = stack -> top; i >= 0; i--) {
        printf("%d ", stack -> arr[i]);
    }
    printf("\n");
}


int main() {
    int choice, val, size;

    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    struct Stack* stack = createStack(size);

    while (1) {
        printf("\n--- Stack Operations ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(stack, val);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                peek(stack);
                break;
            case 4:
                display(stack);
                break;
            case 5:
                free(stack->arr);
                free(stack);
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
