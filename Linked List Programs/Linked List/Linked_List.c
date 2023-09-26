#include <stdio.h>
#include <stdlib.h>

typedef struct N{
    int data;
    struct N* next;
}node;

node* head = NULL;
node* temp;

void insertFront(){
    int data;
    printf("Enter element to insert front:");
    scanf("%d",&data);
    node *newn = (node*)malloc(sizeof(node));
    newn->data = data;
    if(head==NULL){
        newn->next = NULL;
        head = newn;
        printf("%d inserted at front\n",head->data);
        return;
    }
    newn->next = head;
    head = newn;
    printf("%d inserted at front\n",head->data);
}

void insertBack(){
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

void insertPos(){
    int data;
    printf("Enter element to insert at position:");
    scanf("%d",&data);
    node *newn = (node*)malloc(sizeof(node));
    newn->data = data;
    if(head==NULL){
        printf("Position doesn't exist in list\n");
        return;
    }
    int pos;
    printf("Enter position to be entered:");
    scanf("%d",&pos);
    temp=head;
    int i;
    for(i=0;i<pos;i++){
        temp=temp->next;
        if(temp==NULL){
            printf("Position doesn't exist in list\n");
            return;
        }
    }
    newn->next = temp->next;
    temp->next=newn;
    printf("%d inserted at position %d\n",data,pos);
}

void deleteFront(){
    if(head==NULL){
        printf("List Empty\n");
        return;
    }
    temp = head;
    head = head->next;
    printf("%d deleted from front\n",temp->data);
    free(temp);
}

void deleteBack(){
    if(head==NULL){
        printf("List Empty\n");
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

void deletePos(){
    if(head==NULL){
        printf("List Empty\n");
        return;
    }
    int pos;
    printf("Enter position to be deleted:");
    scanf("%d",&pos);
    temp=head;
    int i;
    for(i=0;i<pos;i++){
        temp=temp->next;
        if(temp->next==NULL){
            printf("Position doesn't exist in list\n");
            return;
        }
    }
    node* ptr = temp->next;
    temp->next = temp->next->next;
    printf("%d deleted from position %d",ptr->data,pos);
    free(ptr);
}

void traverse(){
     if(head==NULL){
        printf("List Empty\n");
        return;
    }
    temp=head;
    printf("List elements are:\n");
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

void main(){
    int choice;
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Back\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Front\n");
        printf("5. Delete from Back\n");
        printf("6. Delete from Position\n");
        printf("7. Traverse List\n");
        printf("8. Exit\n");
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
                insertPos();
                break;
            case 4:
                deleteFront();
                break;
            case 5:
                deleteBack();
                break;
            case 6:
                deletePos();
                break;
            case 7:
                traverse();
                break;
            case 8:
                printf("Program Ended");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return ;
}
