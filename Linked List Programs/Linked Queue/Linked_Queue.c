#include <stdio.h>
#include <stdlib.h>

typedef struct N{
    int data;
    struct N* next;
}node;

node* head = NULL;
node* temp;

void enqueue(){
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

void dequeue(){
    if(head==NULL){
        printf("Queue Empty\n");
        return;
    }
    temp = head;
    head = head->next;
    printf("%d deleted from front\n",temp->data);
    free(temp);
}

void display(){
    if(head==NULL){
        printf("Queue Empty\n");
        return;
    }
    temp=head;
    printf("Queue elements are:\n");
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

void frontDis(){
   if(head==NULL){
        printf("Queue Empty\n");
        return;
    }
    temp=head;
    printf("Front element of queue is");
    printf("%d\n",head->data);
}


void main(){
     int choice;

    while (1) {
        printf("Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Front\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                frontDis();
                break;
            case 5:
                printf("Program Ended");
                return; // Exit the program
            default:
                printf("Invalid choice\n");
        }
    }

    return;
}