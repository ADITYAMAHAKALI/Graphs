#include "directedGraph.h"

int main(){
    srand(time(0));
    dgraph g;
    initializeGraph(&g,5); 
    generateGraph(&g,0.5,1);
    printGraph(&g);
}