#include"weightedUnDirectedGraph.h"

int main(){
    srand(time(0));
    wudgraph G;
    int v,n;
    double prob;
    v=5;n=20; 
    prob  = 1;
    initializeGraph(&G,v);
    edge *edges = generateEdges(v,n,prob);
    printEdges(edges,n);
    createGraph(&G,edges,n);
    printGraph(&G);

}