#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <unistd.h>
#include<ncurses.h>
#include "matrix.h"
#include "cellQueue.h"

#define cellWidth 3
#define cellHeight 3
int  width =   cellWidth *20;
int  height = cellHeight *10;
void draw(WINDOW *win,Graph *G);
bool find = false;


int bfs(WINDOW *win,Graph *G){
    
    queue cells; // queue of cells
    initializeQueue(&cells,G->vertices);
    enqueue(&cells,G->mat[0]);
    G->mat[0].visited = true;
    G->mat[0].visited = 1;
    cell vis;
    int r = G->rows;
    int c = G->cols;
    while(!empty(&cells)){
       // wgetch(win);
        vis = dequeue(&cells);
        draw(win,G);
        if(find){
            return 1;
        }
        if(vis.value == 2){
            printf("success");
            find =true;
            return 1;
        }
        // now we need to visit all 8 neightbours of the cell if they exist and put them 
        // range of i: 0<=i<G->vertices, range of j 0<=G->vertices
        // in queueue
        // top same col, upper row (i,j)-> (i,j-1)
        if(vis.j>=1 && G->mat[vis.i *r +(vis.j-1)].visited==0){
            if(G->mat[vis.i *r +(vis.j-1)].value ==2){
                mvprintw(0,0,"success");
                find =true;
                return 1;
            }
            enqueue(&cells,G->mat[vis.i *r +(vis.j-1)]);
            G->mat[vis.i *r +(vis.j-1)].visited = true;
            G->mat[vis.i *r +(vis.j-1)].value =1; 
        }
        // top right (i,j)->(i+1,j-1)
        // if(vis.j>=1 && vis.i<r-1 && G->mat[(vis.i+1) *r +(vis.j-1)].visited==0){
        //     if(G->mat[vis.i+1 *r +(vis.j-1)].value ==2){
        //         mvprintw(0,0,"success");
        //         find =true;
        //         return 1;
        //     }
        //     enqueue(&cells,G->mat[(vis.i+1) *r +(vis.j-1)]);
        //     G->mat[(vis.i+1) *r +(vis.j-1)].visited = true;
        // }
        // right (i,j)->(i+1,j)
        if(  vis.i<r-1 && G->mat[(vis.i+1) *r +(vis.j)].visited==0){
            if(G->mat[vis.i+1 *r +(vis.j)].value ==2){
                mvprintw(0,0,"success");
                find =true;
                return 1;
            }
            enqueue(&cells,G->mat[(vis.i+1) *r +(vis.j)]);
            G->mat[(vis.i+1) *r +(vis.j)].visited = true;
            G->mat[(vis.i+1) *r +(vis.j)].value = 1;
        }
        // bottom-right (i,j)->(i+1,j+1)
        // if(vis.j<c-1 && vis.i<r-1 && G->mat[(vis.i+1) *r +(vis.j+1)].visited==0){
        //     if(G->mat[vis.i+1 *r +(vis.j+1)].value ==2){
        //         mvprintw(0,0,"success");
        //         find =true;
        //         return 1;
        //     }
        //     enqueue(&cells,G->mat[(vis.i+1) *r +(vis.j+1)]);
        //     G->mat[(vis.i+1) *r +(vis.j+1)].visited = true;
        // }
        // bottom (i,j)->(i,j+1) 
        if(vis.j<c-1  && G->mat[(vis.i) *r +(vis.j+1)].visited==0){
            if(G->mat[vis.i *r +(vis.j+1)].value ==2){
                mvprintw(0,0,"success");
                find =true;
                return 1;
            }
            enqueue(&cells,G->mat[(vis.i) *r +(vis.j+1)]);
            G->mat[(vis.i) *r +(vis.j+1)].visited = true;
            G->mat[(vis.i) *r +(vis.j+1)].value = 1;
        }
        // bottom-left (i,j)->(i-1,j+1)
        // if(vis.j<c-1 && vis.i>=1 && G->mat[(vis.i-1) *r +(vis.j+1)].visited==0){
        //     if(G->mat[vis.i-1 *r +(vis.j+1)].value ==2){
        //         mvprintw(0,0,"success");
        //         find =true;
        //         return 1;
        //     }
        //     enqueue(&cells,G->mat[(vis.i-1) *r +(vis.j+1)]);
        //     G->mat[(vis.i-1) *r +(vis.j+1)].visited = true;
        // }

        // left (i,j)->(i-1,j)
        if( vis.i>=1 && G->mat[(vis.i-1) *r +(vis.j)].visited==0){
            if(G->mat[vis.i-1 *r +(vis.j)].value ==2){
                mvprintw(0,0,"success");
                find =true;
                return 1;
            }
            enqueue(&cells,G->mat[(vis.i-1) *r +(vis.j)]);
            G->mat[(vis.i-1) *r +(vis.j)].visited = true;
            G->mat[(vis.i-1) *r +(vis.j)].value = 1;
        }
        // top-left (i,j)->(i-1,j-1)
        // if(vis.j>=1 && vis.i>=1 && G->mat[(vis.i-1) *r +(vis.j-1)].visited==0){
        //     if(G->mat[vis.i-1 *r +(vis.j-1)].value ==2){
        //         mvprintw(0,0,"success");
        //         find =true;
        //         return 1;
        //     }
        //     enqueue(&cells,G->mat[(vis.i-1) *r +(vis.j-1)]);
        //     G->mat[(vis.i-1) *r +(vis.j-1)].visited = true;
        // }
    }
    return -1;

}

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
    createGoal(&G);
    draw(win,&G);
    bfs(win,&G);
    refresh();
    if(find){
        mvwprintw(win,0,0,"Goal Node Found");
    }
    wgetch(win);
    getchar();
    sleep(100);
    endwin();
    outputGraph(&G);
    printf("\n");

    return 0;
}