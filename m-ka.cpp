#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_PLUS 43
#define KEY_MINUS 45
#define KEY_LESS 44
#define KEY_GREATER 46
#define KEY_ESCAPE 27
void gotoxy(short x, short y);
void print_M(int xo, int yo, int max, int wcase);
void clearScreen();

int main() {
    SetConsoleOutputCP(437);
    int x=0, y=0;
    int max=5;
    int wcase=1;
    print_M(x, y, max, wcase);
    while(1) {
        gotoxy(x,y);
        int c;
        switch(c=getch()) {
            case KEY_UP:
                if(y>0) {
                    y--;
                }
            break;
            case KEY_DOWN:
                y++;
            break;
            case KEY_LEFT: if(x>0) {
                x--;
            }
            break;
            case KEY_RIGHT:
                x++;
            break;
            case KEY_PLUS:
                if(y>1) {
                    max+=2;
                    y-=2;
                }

            break;
            case KEY_MINUS:
                if(max>6) {
                    max-=2;
                    y+=2;
                }
            break;
            case KEY_GREATER:
                if(wcase==1) {
                    y=y+max-1;
                    wcase++;
                }else if(wcase==2 && x>max-2) {// czemu x>max-2, a nie x>max-1
                    x=x-max+1;
                    wcase++;
                }else if(wcase==3 && y>max-2) { // czemu y>max-2, a nie y>max-1
                    y=y-max+1;
                    wcase++;
                }else if(wcase==4) {
                    x=x+max-1;
                    wcase=1;
                }
            break;
            case KEY_LESS:
                if(wcase==1 && x>max-2) {// czemu x>max-2, a nie x>max-1
                    x=x-max+1;
                    wcase=4;
                }else if(wcase==2 && y>max-2) {// czemu y>max-2, a nie y>max-1
                    y=y-max+1;

                    wcase--;
                }else if(wcase==3) {
                    x=x+max-1;
                    wcase--;
                }else if(wcase==4) {
                    y=y+max-1;
                    wcase--;
                }
            break;
            case KEY_ESCAPE:
                return 0;
        }
    clearScreen();
    print_M(x,y, max, wcase);
    }
    return 0;
}
    void print_M(int xo, int yo, int max, int wcase){
        switch(wcase) {
            case 1:
                for (int y = 0; y < max; y++) {
                    for(int x = 0; x < max; x++) {
                        gotoxy(x+xo,y+yo);
                        if(x==0 || x==max-1) {
                            printf("M");
                        }
                        else if(x==y && y<=max/2){
                            printf("M");
                        }else if(x == max-y-1 && y<=max/2) {
                            printf("M");
                        }else {
                            printf(" ");
                        }
                    }
                    printf("\n");
                }
            break;
            case 2:
                for (int y = 0; y < max; y++) {
                    for(int x = 0; x < max; x++) {
                        gotoxy(x+xo,y+yo);
                        if(y==0 || y==max-1) {
                            printf("M");
                        }
                        else if(x==y && y>=max/2) {
                            printf("M");
                        }else if(x == max-y-1 && y<=max/2) {
                            printf("M");
                        }else {
                            printf(" ");
                        }
                    }
                    printf("\n");
                }
            break;
            case 3:
                for (int y = 0; y < max; y++) {
                    for(int x = 0; x < max; x++) {
                        gotoxy(x+xo,y+yo);
                        if(x==0 || x==max-1) {
                            printf("M");
                        }
                        else if(x==y && y>=max/2){
                            printf("M");
                        }else if(x == max-y-1 && y>=max/2) {
                            printf("M");
                        }else {
                            printf(" ");
                        }
                    }
                    printf("\n");
                }
            break;
            case 4:
                for (int y = 0; y < max; y++) {
                    for(int x = 0; x < max; x++) {
                        gotoxy(x+xo,y+yo);
                        if(y==0 || y==max-1) {
                            printf("M");
                        }
                        if(x==y && y<=max/2){
                            printf("M");
                        }else if(x == max-y-1 && y>=max/2) {
                            printf("M");
                        }else {
                            printf(" ");
                        }
                    }
                    printf("\n");
                }
            break;
        }
    }
    void gotoxy(short x, short y){
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD position = {x , y};
        SetConsoleCursorPosition( hStdout, position);
    }
    void clearScreen(){
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(hConsole, &csbi);
        DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;
        COORD topLeft = {0, 0};
        DWORD charsWritten;

        FillConsoleOutputCharacter(hConsole, ' ', consoleSize, topLeft, &charsWritten);
        SetConsoleCursorPosition(hConsole, topLeft);
    }
