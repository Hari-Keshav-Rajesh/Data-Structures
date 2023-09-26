#include <stdio.h>

#define max 10

int queue[10];

int front = 0;
int rear = -1;
int count = 0;

void insertFront() {
    if (count==max) {
        printf("Queue full\n");
        return;
    }
    int data;
    printf("Enter element to be inserted: ");
    scanf("%d", &data);
    if (front == 0) {
        front = max - 1;
        queue[front] = data;
        printf("%d inserted to front of queue\n", data);
        count++;
        return;
    }
    queue[--front] = data;
    count++;
    printf("%d inserted to front of queue\n", data);
}

void insertBack() {
    if (count==max) {
        printf("Queue full\n");
        return;
    }
    int data;
    printf("Enter element to be inserted: ");
    scanf("%d", &data);
    if (rear == max - 1) {
        rear = 0;
        queue[rear] = data;
        printf("%d inserted to back of queue\n", data);
        count++;
        return;
    }
    queue[++rear] = data;
    count++;
    printf("%d inserted to back of queue\n", data);
}

void deleteFront() {
    if (count==0) {
        printf("Queue Empty\n");
        return;
    }
    if (front == rear) {
        front = 0;
        rear = -1;
    }
    if (front == max - 1) {
        printf("%d deleted from front of queue\n", queue[front]);
        front = 0;
        count--;
        return;
    }
    printf("%d deleted from front of queue\n", queue[front]);
    front++;
}

void deleteBack() {
    if (count==0) {
        printf("Queue Empty\n");
        return;
    }
    if (front == rear) {
        front = 0;
        rear = -1;
    }
    if (rear == 0) {
        printf("%d deleted from back of queue\n", queue[rear]);
        rear = max - 1;
        count--;
        return;
    }
    printf("%d deleted from back of queue\n", queue[rear]);
    count--;
    rear--;
}

void display() {
    if (count==0) {
        printf("Queue Empty\n");
        return;
    }
    int i;
    printf("Queue elements are:\n");

    if(front<=rear){
        for (i = front; i <= rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
    else{
        for (i = front; i < max; i++) {
            printf("%d\n", queue[i]);
        }
        for (i = 0; i <= rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Insert at Front\n2. Insert at Back\n3. Delete from Front\n4. Delete from Back\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertFront();
                break;
            case 2:
                insertBack();
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteBack();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0; // Exit the program
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
