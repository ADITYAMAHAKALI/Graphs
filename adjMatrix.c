#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

typedef struct AdjacencyMatrix{
    int *mat; 
    int vertices;
    int edges;
}adjMatrix; 


void initializeAdjMatrix(adjMatrix *G, int v){
    G->vertices = v; 
    G->mat = (int*)malloc(sizeof(int)*v*v);
    G->edges = 0;
}

void inputGraph(adjMatrix *G){
    int v = G->vertices;
     
    for(int i=0;i<v; i++){
       
        for(int j=0;j<v;j++){
           l1: printf("Enter 1 if there is an edge from vertex %d to vertec %d, else 0 ",i,j);
            scanf("%d",(G->mat+i*v+j));
            if(*(G->mat+i*v+j) == 1 || *(G->mat+i*v+j) == 0){
                if(*(G->mat+i*v+j) == 1){
                   G->edges++;
                 }
            }else{
                goto l1;
            }
            
        }
    } 
}

void generateGraph(adjMatrix *G,float prob,bool selfLoop){
    int v = G->vertices;
    int r;
    for(int i=0;i<v; i++){
        for(int j=0;j<v;j++){
            r = rand()%10;
            if(r<=prob*10){
                if(selfLoop || i!=j){ 
                    *(G->mat+i*v+j)=1;
                    G->edges++;
                }
            }else{
                 *(G->mat+i*v+j)=0;
            }
        }
    } 
}
void outputGraph(adjMatrix *G){
    int v = G->vertices;
    printf("   ");
    for(int i=0;i<v; i++){
         printf("%d  ",i);
     }
     printf("\n   ");
     for(int i=0;i<v; i++){
         printf("__ ");
     }
      printf("\n");
    for(int i=0;i<v; i++){
         printf("%d | ",i);
        for(int j=0;j<v;j++){
            printf("%d  ",*(G->mat+i*v+j));
        }
        printf("\n\n");
    } 
    printf("The graph has %d vertices and %d edges",G->vertices,G->edges);
}

int main(){
    // the dimension of this matrix will depend on number of vertices 
    srand(time(0));
    bool selfLoop = false;
    adjMatrix G; // directedGraph
    int n;
    float p;
    printf("\nHow many vertices do you want : ");
    scanf("%d",&n);
    printf("\nProbabiltiy(between 0 and 1) of edge between any two vertices : ");
    scanf("%f",&p);
    initializeAdjMatrix(&G,n);
    generateGraph(&G,p,selfLoop);
    outputGraph(&G);
    printf("\n");
}