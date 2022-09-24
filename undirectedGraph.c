#include"undirectedGraph.h"
int main(){
    srand(time(0));
    udgraph g;
    initializeGraph(&g,10); // 0,1,2
    generateGraph(&g,0.3,1);

    printGraph(&g);
    
}