#ifndef MATRIXH
#define MATRIXH
#include<ncurses.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

void red () {
  printf("\033[1;31m");
}
void reset () {
  printf("\033[0m");
}
void yellow(){
  printf("\033[1;33m");
}


typedef struct Cell{
    int i,j,visited,value;
}cell;

int max(int a,int b){

    if(a>=b){
        return a;
    }
    return b;
}

typedef struct AdjacencyMatrix{
    cell *mat;
    int rows;
    int cols;
    int vertices; // size of the matrix
    int edges;
}Graph; 

void initializeAdjMatrix(Graph *G, int r,int c){
    G->rows = r;
    G->cols =c;
    G->vertices = r*c; 
    G->mat = (cell*)malloc(sizeof(cell)*r*c);
    G->edges = 0;
}

void generateGraph(Graph *G,float prob){
    int r = G->rows;
    int c = G->cols;
    int k;
    for(int i=0;i<r; i++){
        for(int j=0;j<c;j++){

            G->mat[i*r+j].i = i; 
            G->mat[i*r+j].j = j;
            G->mat[i*r+j].visited = 0;

            k = rand()%10;
            if(k<=prob*10){
                G->mat[i*r+j].value = -1; // represents obstacle i.e. can never visit that node
                G->mat[i*r+j].visited = 1;
            }else{
                G->mat[i*r+j].value = 0; // i.e. i can travel on this node of the graph
                G->edges++;
            }
        }
    } 
}

void createGoal(Graph *G){
    int n = G->vertices;
    int i = max(2,rand()%G->rows);
    int j = max(2,rand()%G->cols);
    G->mat[i*G->rows + j].value =2;
    G->mat[0].value = 0; //initial square must be zero
}

void outputGraph(Graph *G){
    int r = G->rows;
    int c = G->cols;
    printf("   ");
    for(int i=0;i<r; i++){
         printf("%d    ",i);
     }
     printf("\n   ");
     for(int i=0;i<c; i++){
         printf("__   ");
     }
      printf("\n");
    for(int i=0;i<r; i++){
         printf("%d | ",i);
        for(int j=0;j<c;j++){
            if(G->mat[i*r+j].value == 2){
                red();
                printf("%-3d  ",G->mat[i*r+j].value);
                reset();
            }else if(G->mat[i*r+j].value == -1){
                yellow();
                printf("%-3d  ",G->mat[i*r+j].value);
                reset();
            }else{
                printf("%-3d  ",G->mat[i*r+j].value);
            }
        }
        printf("\n\n");
    } 
    printf("The graph has %d verices and %d edges",G->vertices,G->edges);
}

#endif 