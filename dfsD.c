#include "weightedUnDirectedGraph.h"
#include "stack.h"

void dfs(wudgraph *G,int x){
    int visited[G->vertices];
    for(int i=0;i<G->vertices ;i++){
        visited[i] = 0;
    } 
    stack s;
    initializeStack(&s,G->vertices);
    int y =0 ;
    push(&s,y);
    visited[y]=1;
    int neighbour;
    while(!(empty(&s))){
        printStack(&s);
        y= top(&s);
        if(y==x){
            printf("\n%d is found on top of the stack",x);
            break;
        }
        pop(&s);
       
        visited[y] = true;
        node *temp = G->list[y].head;
        while(temp!=NULL){
            if(visited[temp->dest] == 0){
                if(temp->dest == x){
                    printStack(&s);
                    printf("\n%d is found as a neighbour of front of the stack node %d",x,y);
                    return;
                }
                push(&s,temp->dest);
                visited[temp->dest] =1;
            }
            temp = temp->next;
        }
    }
}

int main(){
     srand(time(0));
    
    wudgraph G;
    int n,e,target;
    float p;
    printf("\nHow many vertices do you want : ");
    scanf("%d",&n);
    printf("\nHow many edges do you want : ");
    scanf("%d",&e);
    printf("\nProbabilty(between 0 and 1) of edge between any two vertices : ");
    scanf("%f",&p);
    initializeGraph(&G,n);
    edge *edges = generateEdges(n,e,p);
    printf("\nEdges:\n");
    printEdges(edges,n);
    printf("\nMy Graph :\n");
    createGraph(&G,edges,n);
    printGraph(&G);
    printf("\nEnter the vertex you want to search : ");
    scanf("%d",&target);
    dfs(&G,target);
    printf("\n");
}