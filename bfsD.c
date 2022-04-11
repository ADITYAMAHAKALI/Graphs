#include"weightedUnDirectedGraph.h"
#include "queue.h"

void appendNeighbours(queue *q,linkedList ll,int visited[]){
    node *temp = ll.head;
    while(temp!=NULL){
        if(visited[temp->dest] == 0){
            enqueue(q,temp->dest);
            visited[temp->dest] = 1;
        }
        temp = temp->next;
    }
}

void bfs(wudgraph *G,int x){
    int visited[G->vertices];
    for(int i=0;i<G->vertices ;i++){
        visited[i] = 0;
    }
    queue q;
    int y;
    initializeQueue(&q,G->vertices);
    int i=0;
    if(G->list[i].head !=NULL){
        i++;
    }
    enqueue(&q,i); 
    visited[i] =1 ;
    while(!empty(&q)){
        y = peek(&q);
        if(y == x){
            printf("\n%d is found",x);
            break;
        }
        appendNeighbours(&q,G->list[y],visited);
        printf("%d ",y);
        dequeue(&q);
    }
    if(empty(&q)){
        printf("\n%d is not found in the graph",x);
    }
    
}

int main(){
    wudgraph G;
    int v,n;
    double prob;
    v=10;n=20; 
    prob  = 1;
    initializeGraph(&G,v);
    edge *edges = generateEdges(v,n,prob);
    printEdges(edges,n);
    createGraph(&G,edges,n);
    printGraph(&G);
    bfs(&G,6);
    printf("\n");
}

