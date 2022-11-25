#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;
void push(){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to push:");
    scanf("%d",&temp->data);
    temp->next=NULL;   
    if(head==NULL){
        head=temp;
    }
    else{
    temp->next=head;
    head=temp;}
}
void pop(){
    if(head==NULL){
        printf("Underflow\n");
    }
    else{
        printf("%d popped\n",head->data);
        // LONG WAY

        // struct node*ptr=(struct node*)malloc(sizeof(struct node));
        // ptr=head;
        // ptr=ptr->next;
        // free(head);
        // head=ptr;

        // SHORT WAY FOR DS LAB(IT WILL TAKE MORE MEMORY BUT WE ARE SHORT IN TIME NOT MEMORY)
        head=head->next;
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
printf("Enter \n1 to push\n2 to pop\n3 to display\n4 to exit\n");
while(1){
    printf("Enter choice:");
    scanf("%d",&c);
    switch(c){
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
        exit(0);
        default:
        printf("Enter valid choice");
    }
}
}