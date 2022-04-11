#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

typedef struct Queue{
    int *arr;
    int rear;
    int front;
    int size;
} queue; 

void initializeQueue(queue *q,int size){
    q->arr = (int *)malloc(sizeof(int)* (size));
    q->rear = -1;
    q->front = -1;
    q->size = size;
}

void enqueue(queue *q,int x){
    int t;
    if(q->rear < q->size -1){
        if(q->front ==-1){
         q->front = 0;
    }
        *(q->arr + ++q->rear) = x ;
    }
    else{
        printf("\nMemory Overflow queue is full \n");
    }
}

int dequeue(queue *s){
    if(s->front == -1 || s->front > s->rear){
        printf("\nMemory underflow can't remove");
        return -1;
    }
    else{
        return *(s->arr + s->front++) ;
    }
}

int peek(queue *q){
    if(q->rear == -1 && q->front ==-1){
        printf("\nEmpty queue !!");
        return -1;
    }else{
        return *(q->arr + q->front) ;
    }
}

void printQueue(queue *q){
    if(q->rear ==-1){
        printf("\nEmpty Queue!!!\n");
    }else{
        for(int i=q->front ; i<=q->rear ;i++){
            printf("%d\n", *(q->arr+i));
        }
    }
}
bool empty(queue *q){
    if(q->front > q->rear || q->rear == -1 )
        return true;
    return false;
}