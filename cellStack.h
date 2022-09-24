#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

typedef struct Stack{
    cell *arr;
    int top;
    int size;
} stack; 

void initializeStack(stack *s,int size){
    s->size = size;
    s->arr = (cell *)malloc(sizeof(cell)* size);
    s->top = -1; 
}

void increaseSize(stack *s){
    s->arr = (cell *)realloc(s->arr,2* s->size);
    s->size *=2;
}

void push(stack *s,cell x){
    if(s->top < s->size -1){
        *(s->arr + ++s->top ) = x ;
    }
    else{
        printf("\nMemory Overflow stack is full \n");
    }
}

cell pop(stack *s){
        return *(s->arr + s->top--) ;
}

cell top(stack *s){
    cell t;// temperory cell
    t.i=-1;
    t.j=-1;
    t.value=-1;
    t.visited=1;
    if(s->top == -1){
        printf("\nEmpty stack !!");
        return t;
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
            printf("%d %d %d\n", s->arr[i].i , s->arr[i].j, s->arr[i].value);
        }
    }
}

bool empty(stack *s){
    return (s->top == -1) ;
}