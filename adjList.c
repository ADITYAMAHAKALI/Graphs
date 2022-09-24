#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
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

typedef struct adJacenyList{ // adjcaceny List basic undirected graph 
    linkedList *list;
    int vertices;
    int edges;
}graph;

void initializeGraph(graph *G,int vertices){
    G->vertices = vertices;
    G->edges = 0;
    G->list = (linkedList*)malloc(sizeof(linkedList)*vertices);
    
}

void addEdge(graph *G,int u,int v){
    insertInList(&(G->list[u]),u,v);
    insertInList(&(G->list[v]),v,u);
    G->edges++;
}

void printGraph(graph *G){
    for(int i=0;i<G->vertices; i++){
        printList(G->list[i]);
        printf("\n");
    }
}

void generateGraph(graph *G, float prob,bool selfLoop){ // 0 for self-loops, 1 for no-self loops
    int r ; 
    for(int i =0; i<G->vertices;i++){
        for(int j=i+1;j<G->vertices;j++){
            r =rand()%10;
            //printf("\n%d %f",r,prob*10);
            if(r<=prob*10){
              if(selfLoop || i!=j)
                addEdge(G,i,j);
            }
        }
    }
}

int main(){
   srand(time(0));
   
    bool selfLoop = false;
    graph G;
    int n;
    float p;
    printf("\nHow many vertices do you want : ");
    scanf("%d",&n);
    printf("\nProbabilty(between 0 and 1) of edge between any two vertices : ");
    scanf("%f",&p);
    initializeGraph(&G,n); // 0,1,2
    generateGraph(&G,p,selfLoop);
    printGraph(&G);
}
