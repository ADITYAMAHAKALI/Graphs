#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <unistd.h>
#include<ncurses.h>
#include "matrix.h"
#include "cellStack.h"

#define cellWidth 3
#define cellHeight 3
int  width =   cellWidth *20;
int  height = cellHeight *10;
void draw(WINDOW *win,Graph *G);
bool find = false;

void draw(WINDOW *win,Graph *G){
    if(find){
        return;
    }
    
    refresh();
    
    // wrefresh(win);
    start_color();
    
    init_pair(1,COLOR_BLACK,COLOR_WHITE);

    init_color(COLOR_GREEN,100,400,400);
    init_color(COLOR_RED,999,600,200);
    init_pair(2,COLOR_RED,COLOR_GREEN);
    bkgd(COLOR_PAIR(1));
    wbkgd(win,COLOR_PAIR(2));
   // wrefresh(win);
    //attron(COLOR_PAIR(1));
    
    for(int i=0;i<=height;i+=cellHeight){
        mvwhline(win,i,1,0,width);
    }
    for(int j=0;j<=width;j+=2*cellWidth){
        mvwvline(win,1,j,0,height);
    }
    init_color(COLOR_MAGENTA,600,400,0);
    int x;
    int r=0,c;
    
    for(int i=0;i<=height;i+=cellHeight){
        c= 0;
        for(int j=0;j<=width;j+=2*cellWidth){
            mvwprintw(win,i,j,"%s","*");
            x = G->mat[r * G->rows + c].value;
            if(i==0 && j==0){
                mvwprintw(win,i+1,j+1,"%s","start");     
            }else if(G->mat[r * G->rows + c].visited== true && G->mat[r * G->rows + c].value ==0 ){
                    red();
                    mvwprintw(win,i+1,j+1,"%s","$");
                    reset();
            }else if(x==2){
                mvwprintw(win,i+1,j+1,"%s","Goal"); 
            }else{
                mvwprintw(win,i+1,j+1,"%d",x); 
            }
            c++;
        }
        r++;
    }
   // attroff(COLOR_PAIR(1));
   // wrefresh(win);
    refresh();
    
    printf("\n");
}

void dfsGrid(WINDOW *win, Graph *G){
    stack s;
    initializeStack(&s,G->vertices);
    cell y = G->mat[0];
    push(&s,y);
    y.visited=1;
    cell neighbour;
    int r = G->rows;
    int c = G->cols;
    while(!empty(&s)){
        y= top(&s);
        if(y.value == 2){
            find = true;
            printf("\nGoal is found");
            return;
        }
        // now i need to choose a neighbouring cell
        if(y.j < c-1 && G->mat[y.i * r + y.j+1].visited ==0 ){// right
            neighbour = G->mat[y.i * r + y.j+1];
            neighbour.visited =1;
            push(&s,neighbour);
        }else if(y.i < r-1 &&  G->mat[y.i+1 * r + y.j].visited ==0 ){ // bottom
            neighbour = G->mat[y.i+1 * r + y.j];
            neighbour.visited =1;
            push(&s,neighbour);
        }else if(y.j > 0 &&  G->mat[y.i * r + y.j-1].visited ==0){ //left
            neighbour = G->mat[y.i * r + y.j-1];
            neighbour.visited =1;
            push(&s,neighbour);
        }// top same col, upper row (i,j)-> (i,j-1)
        else if(y.i > 0 &&  G->mat[y.i-1 * r + y.j].visited ==0){ 
            neighbour = G->mat[y.i-1 * r + y.j];
            neighbour.visited =1;
            push(&s,neighbour);
        }else{
            pop(&s);
            continue;
        }

    }
    
        mvwprintw(win,height,width/2,"%s","can not proced further ");
    
}



int main(){
    srand(time(0));
    
    initscr();
    cbreak(); // ctrl+c exit
    noecho();
    curs_set(0);
    WINDOW *win = newwin(height+1,width+1,10,50);
    box(win,0,0);
    // initializing my targeted graph 
    Graph G;
    initializeAdjMatrix(&G, 10,10);
    generateGraph(&G,0.1);
    mvprintw(0,0,"%d",G.vertices);
    createGoal(&G);
    draw(win,&G);
    dfsGrid(win,&G);
    if(find){
        mvwprintw(win,0,0,"Goal Node Found");
    }
    wgetch(win);
    outputGraph(&G);
    endwin();
    printf("\n");

    return 0;
}
