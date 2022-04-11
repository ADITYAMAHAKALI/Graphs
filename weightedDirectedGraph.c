#include"weightedDirectedGraph.h"

int main(){
    srand(time(0));
    wdgraph G;
    int v,n;
    double prob;
    v=5;n=20; 
    prob  = 0.5;
    initializeGraph(&G,v);
    edge *edges = generateEdges(v,n,prob);
    printEdges(edges,n);
    createGraph(&G,edges,n);
    printGraph(&G);
}