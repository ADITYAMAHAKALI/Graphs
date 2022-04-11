#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"linkedList.h"


void insertInList(linkedList *ll,int s,int d){
    node *temp,*src,*dest;
    if(ll->head == NULL){
        src = (node*)malloc(sizeof(node));
        src->data = s;
        src->next = NULL;
        ll->head = src;
    }
    dest = (node*)malloc(sizeof(node));
    dest->data = d;
    dest->next = NULL;
    temp = ll->head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = dest;
}

typedef struct DirectedGraph{ // adjcaceny List basic undirected graph 
    linkedList *list;
    int vertices;
    int edges;
}dgraph;

void initializeGraph(dgraph *G,int vertices){
    G->vertices = vertices;
    G->edges = 0;
    G->list = (linkedList*)malloc(sizeof(linkedList)*vertices);
}

void addEdge(dgraph *G,int u,int v){
    insertInList(&(G->list[u]),u,v);
    G->edges++;
}

void printGraph(dgraph *G){
    for(int i=0;i<G->vertices; i++){
        printList(G->list[i]);
        printf("\n");
    }
}

void generateGraph(dgraph *G, float prob,int isSimple){ // 0 for self-loops, 1 for no-self loops
    int r ; 
    for(int i =0; i<G->vertices;i++){
        for(int j=0;j<G->vertices;j++){
            if(i==j && isSimple){
                continue;
            }
            r = rand()%10;
            if(r <= prob *10){
                addEdge(G,i,j);
            }
        }
    }
}

