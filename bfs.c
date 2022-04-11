

#include "directedGraph.h"

#include "queue.h"

void appendNeighbours(queue *q,linkedList ll,int visited[]){
    node *temp = ll.head;
    while(temp!=NULL){
        if(visited[temp->data] == 0){
            enqueue(q,temp->data);
            visited[temp->data] = 1;
        }
        temp = temp->next;
    }
}

void bfs(dgraph *G,int x){
    int visited[G->vertices];
    for(int i=0;i<G->vertices ;i++){
        visited[i] = 0;
    }
    queue q;
    int y;
    initializeQueue(&q,G->vertices);
    int i=0;
    while(G->list[i]->head ==NULL){
       i++;
    }
    enqueue(&q,G->list->head->data); 
    visited[G->list->head->data] =1 ;
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
     srand(time(0));
    dgraph g;
    initializeGraph(&g,5); 
    generateGraph(&g,0.5,1);
    printGraph(&g);
    bfs(&g,3);
    printf("\n");
}