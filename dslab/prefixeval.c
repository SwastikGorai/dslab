#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
float stack[50];
int top=-1;
char pop(){
    return stack[top--];
}
void push(float x){
    stack[++top]=x;
}
float calc(float x,float y,char z){
    if(z=='+'){
        return x+y;
    }
    else if(z=='-'){
        return x-y;   
    }
    else if(z=='*'){
        return x*y;   
    }
    else if(z=='/'){
        return x/y;   
    }
    else return -1;
}
int main(){
    char str[50];
    printf("Enter postfix expression:");
    scanf("%s",&str);
    strrev(str);
    for(int i=0;str[i]!='\0';i++){
        if(isalnum(str[i])){
            push((float)(str[i])-48);
        }
        else{
            float x=(float)(pop());
            float y=(float)(pop());
            push(calc(y,x,str[i]));
        }
    }
    printf("%.2f",stack[0]);
}