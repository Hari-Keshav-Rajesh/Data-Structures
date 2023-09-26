#include <stdio.h>
#include <stdlib.h>

typedef struct N{
    int data;
    struct N* next;
}node;

node* head = NULL;
node* temp;

void push(){
    int data;
    printf("Enter element to insert back:");
    scanf("%d",&data);
    node *newn = (node*)malloc(sizeof(node));
    newn->data = data;
    newn->next=NULL;
    if(head==NULL){
        newn->next = NULL;
        head = newn;
        printf("%d inserted at back\n",newn->data);
        return;
    }
    temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next=newn;
    printf("%d inserted at back\n",newn->data);
}

void pop(){
    if(head==NULL){
        printf("Stack Empty\n");
        return;
    }
    if(head->next==NULL){
        temp=head;
        head = NULL;
        printf("%d deleted from back\n",temp->data);
        free(temp);  
    }
    temp = head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    node* ptr;
    ptr = temp->next;
    printf("%d deleted from back\n",ptr->data);
    temp->next = NULL;
    free(ptr);
}

void display(){
    if(head==NULL){
        printf("Stack Empty\n");
        return;
    }
    temp=head;
    printf("Stack elements are:\n");
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

void peek(){
    if(head==NULL){
        printf("Stack Empty\n");
        return;
    }
    temp=head;
    printf("Top element of stack is");
    while(temp!=NULL){
        temp=temp->next;
    }
    printf("%d\n",temp->data);
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