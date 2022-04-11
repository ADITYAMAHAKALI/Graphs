#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

node *createNode(int x){
    node *temp = (node*)malloc(sizeof(node));
    temp->data = x ; 
    temp->next = NULL;
    return temp;
}

typedef struct LinkedList{
    node *head;
    int len;
}linkedList; 

void printList(linkedList ll){
    node *temp = ll.head;
    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
