#include <stdio.h>

#define max 20
#define size 10

int stack[max];

int top[max/size];
int boundary[(max/size)+1];

int i;

void push(){
    if(top[i]==boundary[i+1]){
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter element to be pushed\n");
    scanf("%d",&stack[++top[i]]);
    printf("%d pushed to stack %d\n",stack[top[i]],i);
}

void pop(){
    if(top[i]==boundary[i]){
        printf("Stack Underflow\n");
        return;
    }
    printf("%d popped from stack %d\n",stack[top[i]--],i);
}

void display(){
    if(top[i]==boundary[i]){
        printf("Stack Underflow");
        return;
    }
    printf("Stack elements are:\n");
    int j;
    for(j=top[i];j>boundary[i];j--){
        printf("%d\n",stack[j]);
    }
}

void peek(){
    if(top[i]==boundary[i]){
        printf("Stack Underflow");
        return;
    }
    printf("The top of the stack %d is %d",i,stack[top[i]]);
}

void main(){
    int choice;
    for(i=0;i<(max/size);i++){
    top[i] = ((max/size)*i)-1;
    boundary[i] = top[i];
    }

    boundary[(max/size)] = (max)-1;

    do {
        printf("Enter Stack number to operate on:");
        scanf("%d",&i);
        if(i>(max/size)){
            printf("Max stack value is %d\n",(max/size));
            continue;
        }
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