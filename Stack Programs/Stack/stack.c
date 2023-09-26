#include <stdio.h>

#define max 10

int stack[max];

int top = -1;

void push(){
    if(top==(max-1)){
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter data to be entered:");
    scanf("%d",&stack[++top]);
    printf("%d pushed to stack\n",stack[top]);
}

void pop(){
    if(top==-1){
        printf("Stack Underflow\n");
        return;
    }
    printf("%d popped from stack\n",stack[top]);
    top--;
}

void display(){
    if(top==-1){
        printf("Stack Empty\n");
        return;
    }
    int i;
    printf("Stack elements are:\n");
    for(i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
}

void peek(){
    if(top==-1){
        printf("Stack Underflow\n");
        return;
    }
    printf("Top element of stack is %d\n",stack[top]);
}

void main(){
    int choice;

    do {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return ;
}