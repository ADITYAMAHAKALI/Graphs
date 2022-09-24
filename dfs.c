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
            if(visited[temp->data] == 0){
                if(temp->data == x){
                    printStack(&s);
                    printf("\n%d is found as a neighbour of front of the stack node %d",x,y);
                    return;
                }
                push(&s,temp->data);
                visited[temp->data] =1;
            }
            temp = temp->next;
        }
    }
}

int main(){
    srand(time(0));
    bool selfLoop = false;
    udgraph g;
    int n,target;
    float p;
    printf("\nHow many vertices do you want : ");
    scanf("%d",&n);
    printf("\nProbabilty(between 0 and 1) of edge between any two vertices : ");
    scanf("%f",&p);
    initializeGraph(&g,n); 
    generateGraph(&g,p,selfLoop);
    printGraph(&g);
    printf("\nEnter the vertex you want to search : ");
    scanf("%d",&target);
    dfs(&g,target);
    printf("\n");
}