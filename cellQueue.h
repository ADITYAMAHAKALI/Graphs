#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

typedef struct Queue{
    cell *arr;
    int rear;
    int front;
    int size;
} queue; 

void initializeQueue(queue *q,int size){
    q->arr = (cell *)malloc(sizeof(cell)* (size));
    q->rear = -1;
    q->front = -1;
    q->size = size;
}

void enqueue(queue *q,cell c){
    int t;
    if(q->rear < q->size -1){
        if(q->front ==-1){
         q->front = 0;
    }
        *(q->arr + ++q->rear) = c ;
    }
    else{
        printf("\nMemory Overflow queue is full \n");
    }
}

cell dequeue(queue *s){
    if(s->front == -1 || s->front > s->rear){
        printf("\nMemory underflow can't remove");
        cell t;
        return t;
    }
    else{
        return *(s->arr + s->front++) ;
    }
}

int peekValue(queue *q){
    if(q->rear == -1 && q->front ==-1){
        printf("\nEmpty queue !!");
        return -1;
    }else{
        return (q->arr + q->front)->value ;
    }
}

int peekVisited(queue *q){
    if(q->rear == -1 && q->front ==-1){
        printf("\nEmpty queue !!");
        return -1;
    }else{
        return (q->arr + q->front)->visited ;
    }
}

void front(queue *q){
    int f = q->front;
     printf("i: %d, j: %d, value: %d, visited: %d\n",(q->arr+f)->i, (q->arr+f)->j,(q->arr+f)->visited, (q->arr+f)->value);
}

void printQueue(queue *q){
    if(q->rear ==-1){
        printf("\nEmpty Queue!!!\n");
    }else{
        for(int i=q->front ; i<=q->rear ;i++){
            printf("i: %d, j: %d, value: %d, visited: %d\n",(q->arr+i)->i, (q->arr+i)->j,(q->arr+i)->visited, (q->arr+i)->value);
        }
    }
}

bool empty(queue *q){
    if(q->front > q->rear || q->rear == -1 )
        return true;
    return false;
}