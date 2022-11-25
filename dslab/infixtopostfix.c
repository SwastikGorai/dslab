#include<stdio.h>
#include<ctype.h>
char stack[50];
int top=-1;
void push(char x){
    stack[++top]=x;
}
char pop(){
    return stack[top--];
}
int priority(char x){
    if(x=='('){
        return 0;
    }
    else if(x=='+' || x=='-'){
        return 1;
    }
    else if(x=='*' || x=='/'){
        return 2;
    }
    else return-1;
}
int main(){
    char str[50];
    char x;
    printf("Enter expression:");
    scanf("%s",&str);
    
    for(int i=0;str[i]!='\0';i++){
        if(isalnum(str[i])){
            printf("%c",str[i]);
        }
        else if(str[i]=='('){
            push(str[i]);
        }
        else if(str[i]==')'){
            while((x=pop())!='('){
                printf("%c",x);
            }
        }
        else{
            while(priority(stack[top])>=priority(str[i])){
                printf("%c",pop());
            }
            push(str[i]);
        }
        
    }
    while(top!=-1){
            printf("%c",pop());
        }
}