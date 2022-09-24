#include"pqueue.h"
#include"weightedDirectedGraph.h"
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
  pqueue pq;
  initializePQueue(&pq,n);
  pair c_node;
  int i;
  scanf("%d",&i);
  node *temp = G.list[i].head;
            while(temp!=NULL){
                    insertInPQueue(&pq,temp->dest, temp->weight); 
                temp=temp->next;
            }
  printPQueue(&pq);
   
}