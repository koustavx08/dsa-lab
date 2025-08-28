#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to insert at beginning
void insertAtBeginning(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    printf("%d inserted at beginning.\n", value);
}

// Function to insert at end
void insertAtEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    printf("%d inserted at end.\n", value);
}

// Function to delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    if (head->next == head) {
        head = NULL;
        free(temp);
    } else {
        struct Node *last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next;
        last->next = head;
        free(temp);
    }
    printf("Node deleted from beginning.\n");
}

// Function to delete from end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;
    if (head->next == head) {
        head = NULL;
        free(temp);
    } else {
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        free(temp);
    }
    printf("Node deleted from end.\n");
}

// Function to display list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Main menu-driven program
int main() {
    int choice, value;

    do {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                deleteFromBeginning();
                break;
            case 4:
                deleteFromEnd();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}