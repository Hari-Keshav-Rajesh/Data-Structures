#include <stdio.h>

#define max 10
#define size 5

int stack[max];

int topA = -1;
int topB = max;

void pushA() {
    if (topA == topB - 1) {
        printf("Stack A Overflow\n");
        return;
    }
    printf("Enter data to be entered: ");
    scanf("%d", &stack[++topA]);
    printf("%d pushed to stack A\n", stack[topA]);
}

void pushB() {
    if (topB == topA + 1) {
        printf("Stack B Overflow\n");
        return;
    }
    printf("Enter data to be entered: ");
    scanf("%d", &stack[--topB]);
    printf("%d pushed to stack B\n", stack[topB]);
}

void popA() {
    if (topA == -1) {
        printf("Stack A Underflow\n");
        return;
    }
    printf("%d popped from stack A\n", stack[topA]);
    topA--;
}

void popB() {
    if (topB == max) {
        printf("Stack B Underflow\n");
        return;
    }
    printf("%d popped from stack B\n", stack[topB]);
    topB++;
}

void displayA() {
    if (topA == -1) {
        printf("Stack A Underflow\n");
        return;
    }
    printf("Stack A elements are:\n");
    for (int i = topA; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

void displayB() {
    if (topB == max) {
        printf("Stack B Underflow\n");
        return;
    }
    printf("Stack B elements are:\n");
    for (int i = topB; i < max; i++) {
        printf("%d\n", stack[i]);
    }
}

void peekA() {
    if (topA == -1) {
        printf("Stack A Underflow\n");
        return;
    }
    printf("Top element of stack A is %d\n", stack[topA]);
}

void peekB() {
    if (topB == max) {
        printf("Stack B Underflow\n");
        return;
    }
    printf("Top element of stack B is %d\n", stack[topB]);
}

int main() {
    int choice;

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Push to Stack A\n");
        printf("2. Push to Stack B\n");
        printf("3. Pop from Stack A\n");
        printf("4. Pop from Stack B\n");
        printf("5. Display Stack A\n");
        printf("6. Display Stack B\n");
        printf("7. Peek at Stack A\n");
        printf("8. Peek at Stack B\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                pushA();
                break;
            case 2:
                pushB();
                break;
            case 3:
                popA();
                break;
            case 4:
                popB();
                break;
            case 5:
                displayA();
                break;
            case 6:
                displayB();
                break;
            case 7:
                peekA();
                break;
            case 8:
                peekB();
                break;
            case 9:
                printf("Program Ended\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
