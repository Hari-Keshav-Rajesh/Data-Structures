#include <stdio.h>

#define max 10

int front = 0;
int rear = -1;

int queue[max];

void enqueue(){
    if((rear==(max-1)&&front==0)||(rear=front-1)&&(rear!=-1)){
        printf("Queue full\n");
        return;
    }
    int data;
    printf("Enter data to be enqueued:");
    scanf("%d",&data);
    rear = (rear+1)%max;
    queue[rear] = data;
    printf("%d enqueued\n",queue[rear]);
}

void dequeue(){
    if(front>rear){
        printf("Queue empty");
        return;
    }
    printf("%d dequeued\n",queue[front]);
    front = (front+1)%max;
    if(front==rear){
        front = 0;
        rear = -1;
    }
}

void display(){
    if(front>rear){
        printf("Queue Empty\n");
        return;
    }
    int i;
    printf("Queue elements are:\n");

    for(i=front;i<=rear;i++){
        printf("%d\n",queue[i]);
    }
}

void frontDis(){
    if(front>rear){
        printf("Queue empty\n");
        return;
    }
    printf("Front element of queue is %d\n",queue[front]);
}

void peek(){
    if(front>rear){
        printf("Queue empty\n");
        return;
    }
    printf("Front element of queue is %d\n",queue[front]);
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