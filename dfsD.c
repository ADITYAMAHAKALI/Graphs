#include "weightedUnDirectedGraph.h"
#include "stack.h"

int chooseUnvisitedNeighbour(linkedList ll,int visited[]){
    node *temp = ll.head;
    while(temp->next !=NULL){
        if(visited[temp->dest] == 0){
            return temp->dest;
        }
        temp = temp->next;
    }
    return -1;
}

void dfs(wudgraph *G,int x){
    int visited[G->vertices];
    for(int i=0;i<G->vertices ;i++){
        visited[i] = 0;
    } 
    stack s;
    initializeStack(&s,G->vertices);
    if(G->list->head !=NULL){
        int y =0 ;
        push(&s,y);
        visited[y] = 1;
    }
    
    int neighbour;
    int z;
    while(!(empty(&s))){
        printStack(&s);
        z= top(&s);
        if(z == x){
            printf("\n%d is found",x);
            return;
        }
        
        neighbour = chooseUnvisitedNeighbour(G->list[z],visited);
        if(neighbour!=-1){
            push(&s,neighbour);
            visited[neighbour] = 1;
        }else{
            pop(&s);
        }

    }
}

int main(){
     srand(time(0));
     wudgraph G;
    int v,n;
    double prob;
    v=5;n=10; 
    prob  = 1;
    initializeGraph(&G,v);
    edge *edges = generateEdges(v,n,prob);
    printEdges(edges,n);
    createGraph(&G,edges,n);
    printGraph(&G);
    dfs(&G,4);
    printf("\n");
}