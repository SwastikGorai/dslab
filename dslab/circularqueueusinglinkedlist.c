#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;
struct node* end=NULL;
void insert(){
    struct node* temp=(struct node* )malloc(sizeof(struct node));
    printf("\nEnter data to insert:");
    scanf("%d",&temp->data);
    if(head==NULL){
        head=temp;
        end=temp;
        end->next=head;
        head->next =end;
    }
    else{
        end->next=temp;
        temp->next=head;
        head=temp;
    }
}
void pop(){
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    while(temp->next!=end){
        temp=temp->next;
    }
    temp->next=head;
    free(end);
    end=temp;
}
void display(){
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
}
int main(){
     int c;
printf("Enter \n1 to insert\n2 to delete\n3 to display\n4 to exit\n");
while(1){
    printf("\nEnter choice:");
    scanf("%d",&c);
    switch(c){
        case 1:
        insert();
        break;
        case 2:
        pop();
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
