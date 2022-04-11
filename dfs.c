#include "undirectedGraph.h"
#include "stack.h"

int chooseUnvisitedNeighbour(linkedList ll,int visited[]){
    node *temp = ll.head;
    while(temp->next !=NULL){
        if(visited[temp->data] == 0){
            return temp->data;
        }
        temp = temp->next;
    }
    return -1;
}

void dfs(udgraph *G,int x){
    int visited[G->vertices];
    for(int i=0;i<G->vertices ;i++){
        visited[i] = 0;
    } 
    stack s;
    initializeStack(&s,G->vertices);
    int y =G->list[0].head->data ;
    push(&s,y);
    visited[y] = 1;
    int neighbour;
    while(!(empty(&s))){
        printStack(&s);
        y= top(&s);
        if(y == x){
            printf("\n%d is found",x);
            return;
        }
        
        neighbour = chooseUnvisitedNeighbour(G->list[y],visited);
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
    udgraph G;
    initializeGraph(&G,10);
    generateGraph(&G,0.5,1);
    printGraph(&G);
    dfs(&G,2);
    printf("\n");
}