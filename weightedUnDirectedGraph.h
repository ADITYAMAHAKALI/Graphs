#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef struct Node{
    int dest,weight;
    struct Node *next;
}node;

node *createNode(int d,int w){
    node *temp = (node*)malloc(sizeof(node));
    temp->dest = d ; 
    temp->weight = w;
    temp->next = NULL;
    return temp;
}

typedef struct LinkedList{
    node *head;
    int len;
}linkedList; 

void printList(linkedList ll,int i){
    node *temp = ll.head;
    while(temp!=NULL){
        printf("%d-> %d [%d] ",i, temp->dest,temp->weight);
        temp = temp->next;
    }
    printf("NULL");
}

typedef struct Edge{
    int src,dest,weight;
}edge;

edge* createEdge(int src,int dest,int weight){
    edge *e = (edge*)malloc(sizeof(edge));
    e->dest=dest;
    e->src = src;
    e->weight = weight;
    return e;
}

edge* generateEdges(int v,int n,double prob){
    edge *edges = (edge*)malloc(sizeof(edge) *n );
    int r1,r2,value;
    int i=0,j=1;
    for(int k=0;k<n;){
        r1 = rand()%10;
        if(r1<=prob *10){
            value = rand()%20+1;
            if(i!=j){
                edges[k++] = *(createEdge(i,j,value));
            }
            
            r2 = rand()%10;
            if(r2<5){
                i++;
                i%=v;
            }else{
                j++;
                j%=v;
            }
          
        }
    }
    return edges;
}

void printEdges(edge *edges,int n){
    for(int i=0;i<n;i++){
        printf("(%d->%d, weight = %d)\n",edges[i].src,edges[i].dest,edges[i].weight);
    }
}

typedef struct weightedUndirectedGraph{
    linkedList *list;
    int vertices;
    int edges;
}wudgraph;

 int removeParallelEdges(edge *edges,int n){
     int i,j,k;
  for ( i = 0; i < n; i ++)  
    {  
        for (  j = i + 1;j < n; j++)  
        {  
            if ( edges[i].src == edges[j].src && edges[i].dest == edges[j].dest)  
            {  
                for ( k = j; k < n - 1; k++)  
                {  
                    edges[k].src = edges[k + 1].src;
                    edges[k].dest = edges[k+1].dest; 
                    edges[k].weight = edges[k+1].weight; 
                }  
                n--; 
                j--;
            }        
        }  
    }  
    return n;
 }

void insertInList(linkedList *ll,int d,int w){
    node *temp,*src,*dest;
    if(ll->head == NULL){
        src = (node*)malloc(sizeof(node));
        src->dest = d;
        src->weight = w;
        src->next = NULL;
        ll->head = src;
        return;
    }
    dest = (node*)malloc(sizeof(node));
    dest->dest = d;
    dest->weight  = w;
    dest->next = NULL;
    temp = ll->head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = dest;
}

void initializeGraph(wudgraph *G, int v){
    G->vertices = v;
    G->edges = 0;
    G->list = (linkedList*)malloc(sizeof(linkedList)*v);
}

void createGraph(wudgraph *G, edge *edges,int n){
    
 
    // initialize head pointer for all vertices
    for (int i = 0; i < n; i++) {
        G->list[i].head = NULL;
    }
 
    // add edges to the directed graph one by one
    for (int i = 0; i < n; i++)
    {
        insertInList(&G->list[edges[i].src],edges[i].dest,edges[i].weight);
        insertInList(&G->list[edges[i].dest],edges[i].src,edges[i].weight);
    }
 

}

void printGraph(wudgraph* G)
{
    for(int i=0;i<G->vertices; i++){
        printList(G->list[i],i);
        printf("\n");
    }
}
