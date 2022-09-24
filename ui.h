#ifndef UIH
#define UIH
#include<ncurses.h>
#define MAXX 160
#define MAXY 50

#define MAX_INTENSITY 13
#define MIN_INTENSITY 2

typedef struct Cell{
    char char_value;
    int intensity;
}cell;

cell matrix[MAXX][MAXY];


bool init_ui();
void matrix_update();
void show_update();
void cleanup_ui();
void matrix_init();
void show_matrix();
 
void set_colors(){
    for(int i=0;i<6;i++){
        init_pair(i+1, i , COLOR_BLACK);
    }
     for(int i=0;i<5;i++){
        init_color(i, 0 , i *200,0);
    }
    init_color(6,800,1000,1000);
}
WINDOW *uiwindow = NULL;

int colorMap[MAX_INTENSITY+1] = {1,2,2,3,3,3,4,4,4,4,6,7,8,9};

bool init_ui(){
    uiwindow = initscr();
    if(uiwindow == NULL) return false;
    start_color();
    if(!has_colors() || !can_change_color() || COLOR_PAIRS < 6){
            printf("Failure");
            return false;
    }
    set_colors();
    return true;

}

void cleanup_ui(){
    delwin(uiwindow);
    endwin();
    refresh();
}

void show_matrix(){
     for(int x=0;x<MAXX;x++){
        for(int y=0;y<MAXY;y++){
                int intensity = matrix[x][y].intensity;
                color_set(colorMap[intensity],NULL);
                mvaddch(y,x,matrix[x][y].char_value);
                
         }
    }
    refresh();
}



#endif 