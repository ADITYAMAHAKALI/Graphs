#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

typedef struct Stack{
    int *arr;
    int top;
    int size;
} stack; 

void initializeStack(stack *s,int size){
    s->size = size;
    s->arr = (int *)malloc(sizeof(int)* (size));
    s->top = -1;
}

void increaseSize(stack *s){
    s->arr = (int *)realloc(s->arr,2* s->size);
    s->size *=2;
}

void push(stack *s,int x){
    int t;
    if(s->top < s->size -1){
        *(s->arr + ++s->top ) = x ;
    }
    else{
        printf("\nMemory Overflow stack is full \n");
        // printf("\nDo you want to double the stack size enter 1 to increase the size of stack, any other number to not do this ");
        // scanf("%d",&t);
        // if(t==1){
        //     increaseSize(s);
        //     push(s,x);
        // }else{
        //     return;
        // }
    }
}

int pop(stack *s){
    if(s->top == -1){
        printf("\nMemory underflow cannot pop from empty stack !!\n");
        return -1;
    }else{
        return *(s->arr + s->top--) ;
    }
}

int top(stack *s){
    if(s->top == -1){
        printf("\nEmpty stack !!");
        return -1;
    }else{
        return *(s->arr + s->top) ;
    }
}

void printStack(stack *s){
    printf("\nStatus of stack : \n");
    if(s->top ==-1){
        printf("\nEmpty Stack!!!\n");
    }else{
        for(int i=s->top ; i>=0 ;i--){
            printf("%d\n", *(s->arr+i));
        }
    }
}
bool empty(stack *s){
    return (s->top == -1) ;
}