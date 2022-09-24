#include "directedGraph.h"

#include "queue.h"

int appendNeighbours(queue *q,linkedList ll,int visited[],int goal){
    node *temp = ll.head;
    while(temp!=NULL){
        if(visited[temp->data] == 0){
            if(temp->data == goal){
                return 1;
            }
            enqueue(q,temp->data);
            visited[temp->data] = 1;
        }
        temp = temp->next;
    }
    return 0;
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
    while(G->list[i].head ==NULL){
       i++;
    }
    enqueue(&q,G->list->head->data); 
    visited[G->list->head->data] =1 ;
    while(!empty(&q)){
        printf("\nCurrent status of queue : \n");
        printQueue(&q);
        y = peek(&q);
        if(y == x){
            printf("\n%d is found on front of the queue",x);
            break;
        }
        if(appendNeighbours(&q,G->list[y],visited,x)==1){
            printf("\n%d is found as a neighbour of front of the queue node %d",x,y);
            break;
        }
        //printf("%d ",y);
        dequeue(&q);
    }
    if(empty(&q)){
        printf("\n%d is not found in the graph",x);
    }
    
}

int main(){
    srand(time(0));
    bool selfLoop = false;
    dgraph g;
    int n,target;
    float p;
    printf("\nHow many vertices do you want : ");
    scanf("%d",&n);
    printf("\nProbabilty(between 0 and 1) of edge between any two vertices : ");
    scanf("%f",&p);
    initializeGraph(&g,n); 
    generateGraph(&g,p,selfLoop);
    printGraph(&g);
    printf("\nEnter the vertix you want to search : ");
    scanf("%d",&target);
    bfs(&g,target);
    printf("\n");
}