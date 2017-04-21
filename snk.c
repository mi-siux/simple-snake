#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFF 3
#define ROWS 30
#define COLS 30
#define AST '*'

void printSnake();
void step(int);

int snake[ROWS][COLS] = {[0][0] = 1, [0][1] = 2, [1][1] = 3, [1][2] = 4, [1][3] = 5};
int headRow = 1;
int headCol = 3; 
int head = 5;
char drc = 67;
int grid = 0;

int main(int argc, char* argv[]) {

    system("clear");
 
    char buff[MAX_BUFF] = {'\0'};
    setvbuf(stdin, buff, _IOFBF, MAX_BUFF);

   /*                   NON-CANONICAL MODE                  */ 
    system("stty -echo -icanon min 0 time 0");
    
    while((buff[0] != 27) || (buff[1] != '\0')) {
        
        buff[0] = '\0';
        
        if(buff[2] != '\0') {getchar(); getchar();  buff[1] = '\0'; buff[2] = '\0';}
        if(buff[1] != '\0') {getchar();  buff[1] = '\0';}
 
        getchar();

        if(buff[0] == 'g') {
            if(grid == 0) {
                grid = 1;
            } 
            else {
                grid = 0;
            }
        }

        if(buff[0] == 27) {
                drc = buff[2];
        }
            step(drc);
        
        system("clear");
        
        printSnake();
        system("sleep 0.08");
        //printf(" >>>Pressed: [%d][%d][%d] \n", buff[0], buff[1], buff[2]);

    }
    
    /*              RETURN TO CANONICAL MODE                */
    system("stty icanon echo min 1 time 0");
    system("clear");

    printSnake();


    return 0;
}

void step(int direction) {
    
    
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            if(snake[row][col] != 0) {
                snake[row][col]--;
            }
        }
    }
    
    switch(direction) {
    case 65 : headRow--; snake[headRow][headCol] = head; break;
    case 66 : headRow++; snake[headRow][headCol] = head; break;
    case 67 : headCol++; snake[headRow][headCol] = head; break;
    case 68 : headCol--; snake[headRow][headCol] = head; break;
    }    

}


void printSnake() {

    for(int row = 0; row < ROWS + 1; row++) {
        for(int col = 0; col < COLS; col++) {
            
            if(row != ROWS) {
                snake[row][col] == 0 ? putchar(' ') : putchar(AST);
                printf("%c", col == COLS - 1 ? '\0' : ' ');     //no add space next to right edge
            }
            else {
                putchar('^');   //bottom edge
                putchar(' ');
            }
        } //for col
            
        if(row != ROWS) {
            putchar('.');       //right edge
        } 
        
        putchar('\n');

    } // for row
    
} // function
