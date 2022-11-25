#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next,*prev;
};
struct node*head=NULL;
void insert(){
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    printf("Enter data to insert:");
    scanf("%d",&temp->data);
    if(head==NULL){
        head=temp;
    }
    else{
        int pos;
        printf("Enter pos to insert:");
        scanf("%d",&pos);
        struct node*ptr,*prevptr;
        ptr=head;
        if(pos==0){
            temp->next=ptr;
            ptr->prev=temp;
            head=temp;
        }
        else{
            while(pos--){
                prevptr=ptr;
                ptr=ptr->next;
                if(ptr==NULL){
                    printf("Fewer data than position\n");
                    return;
                }
            }
            prevptr->next=temp;
            temp->prev=prevptr;
            temp->next=ptr;
            ptr->prev=temp;
        }
    }

}
void delete(){
    int pos;
    printf("Enter position to delete:");
    scanf("%d",&pos);
    struct node* temp;
    struct node*prevtemp;
    temp=head;
    if(pos==0){
        temp=temp->next;
        free(head);
        head=temp;
    }
    else{
    while(pos--){
        prevtemp=temp;
        temp=temp->next;
        if(temp==NULL){
            printf("Underflow");
            return;
        }
    }
    prevtemp->next=temp->next;
    prevtemp->next->prev=prevtemp;
    free(temp);
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
        
        printf("Enter valid choice\n");
    }
}
printf("%d",head->next->next->prev->data);
}