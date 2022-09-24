#include"pqueue.h"
#include"weightedDirectedGraph.h"

int uniformCostSearch(wdgraph *G,int goal,int n){
    pqueue pq; // priority queue
    initializePQueue(&pq,n);
    int start;
    int i = 0;
    int visited[G->vertices];
    for(int i=0;i<G->vertices ;i++){
        visited[i]=0;
    }
    while(G->list[i].head == NULL){
        i++;
    }
    start = i;
    insertInPQueue(&pq,i,0);
    visited[i] = 1;

    pair c_node;
    int cost = 0;
    while(pq.curr_size >0){
        c_node = removePriorityNode(&pq);
        printf("\nfrom: %d, ",c_node.dest);
        cost=c_node.cost;
        printf("cost = %d",cost);
        if(c_node.dest == goal){
            return c_node.cost;
        }else{
            // insert all the children of removed elements into the queue 
            // with their cumulative cost as their priorities.
            node *temp = G->list[c_node.dest].head;
            while(temp!=NULL){
                if(visited[temp->dest] == 0){
                    insertInPQueue(&pq,temp->dest,temp->weight);
                    visited[temp->dest] =1;
                }
                temp=temp->next;
            }

        }
    }
    return -1;
}
int main(){
   srand(time(0));
    wdgraph G;
    int v,n;
    double prob;
    v=5;n=20; 
    prob  = 0.8;
    initializeGraph(&G,v);
    edge *edges = generateEdges(v,n,prob);

    printEdges(edges,n);
    n = removeParallelEdges(edges,n);
    printf("\n");
    printEdges(edges,n);
    createGraph(&G,edges,n);
    printGraph(&G);
    printf("\ncost from root node to %d is %d",3,uniformCostSearch(&G,3,n));
    printf("\n");
}