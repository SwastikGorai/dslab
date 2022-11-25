#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node*head=NULL;
struct node*end=NULL;
void insert(){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to push:");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(head==NULL){
        head=temp;
        end=temp;
    }
    else{
        end->next=temp;
        end=temp;
    }
}
void delete(){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    int x;
    if(head==NULL){
        printf("Underflow\n");
    }
    else{
        printf("\n%d deleted\n",head->data);
       
        ptr=head;
        ptr=ptr->next;
        free(head);
        head=ptr;
    }
}
void display(){
     struct node*temp=(struct node*)malloc(sizeof(struct node));
     temp=head;
     while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
     }
     printf("\n");
}
int main(){
    int c;
printf("Enter \n1 to insert\n2 to delete\n3 to display\n4 to exit\n");
while(1){
    printf("Enter choice:");
    scanf("%d",&c);
    switch(c){
        case 1:
        insert();
        break;
        case 2:
        delete();
        break;
        case 3: 
        display();
        break;
        case 4:
        exit(0);
        default:
        printf("Enter valid choice");
    }
}
}