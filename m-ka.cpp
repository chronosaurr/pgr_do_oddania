#include <iostream>
#include <windows.h>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_PLUS 61
#define KEY_MINUS 45
#define KEY_DOT 46
#define KEY_COMA 44

using namespace std;

void gotoxy(short x, short y);
int main() {
    int size = 5;
    int x=1,y=1;
    int rotation = 0;

    while(1) {
        system("cls");
        for(int i=0;i<size;i++) {
            if (rotation==0) {
                gotoxy( x+size-1,y+i-1 );
                cout<<"#";
                gotoxy( x+size+size-2,y+i-1 );
                cout<<"#";
                if (i == 1) {
                    gotoxy(x + size + i - 1, y + i - 1);
                    cout << "#";
                    gotoxy(x + size + size - 3, y + i - 1);
                    cout << "#";
                }
                else if (i < size/2) {
                    gotoxy(x + size + i - 1 , y + i - 1);
                    cout << "#";
                    gotoxy(x + size + size - i - 2 , y + i - 1);
                    cout << "#";
                }
                if (i == size / 2) {
                    gotoxy(x + size + size/2 -1, y + i - 1);
                    cout << "#";
                }
            }
            else if (rotation == 1) {
                gotoxy( x+i+size-1,y+size-2 );
                cout<<"#";
                gotoxy( x+i+size-1,y+2*size-3 );
                cout<<"#";
                if (i == 1) {
                    gotoxy(x + i-2+size+size / 2, y+size/2+size-2);
                    cout << "#";
                }
                else if (i < size/2 && i > 1) {
                    gotoxy(x +i-2+size+size / 2, y+size/2 - i+1+size-2);
                    cout << "#";
                    gotoxy(x + i-2+size+size / 2 , y+size/2+ i - 1+size-2);
                    cout << "#";
                }
                else if (i == size / 2) {
                    gotoxy(x+i-2+size+size / 2, y+1+size-2);
                    cout << "#";
                    gotoxy(x + i-2+size+size / 2, y+size-2+size-2);
                    cout << "#";
                }
            }
            else if (rotation==2) {
                gotoxy( x,y+i-2+size );
                cout << "#";
                gotoxy( x+size-1,y+i-2+size );
                cout<<"#";
                if (i == 1) {
                    gotoxy(x + size/2, y+i-3+size+size / 2);
                    cout << "#";
                }
                else if (i < size/2 && i > 1) {
                    gotoxy(x +size/2 - i+1, y+i-3+size+size / 2);
                    cout << "#";
                    gotoxy(x + size/2+ i - 1 , y+i-3+size+size / 2);
                    cout << "#";
                }
                else if (i == size / 2) {
                    gotoxy(x+1, y+i-3+size+size / 2);
                    cout << "#";
                    gotoxy(x + size - 2, y+i-3+size+size / 2);
                    cout << "#";
                }
            }
            else if (rotation == 3) {
                gotoxy( x+i,y-1 );
                cout<<"#";
                gotoxy( x+i,y+size-2 );
                cout<<"#";
                if (i == 1) {
                    gotoxy(x + i, y + i - 1);
                    cout << "#";
                    gotoxy(x + i, y + size - 3);
                    cout << "#";
                }
                else if (i < size/2) {
                    gotoxy(x + i , y + i - 1);
                    cout << "#";
                    gotoxy(x + i , y + size - i - 2);
                    cout << "#";
                }
                if (i == size / 2) {
                    gotoxy(x + i, y + size/2 -1);
                    cout << "#";
                }
            }
        }
        int c;
        switch(c=getch()) {
            case KEY_UP: y-=1;break;
            case KEY_DOWN: y+=1;break;
            case KEY_LEFT: x-=1;break;
            case KEY_RIGHT: x+=1;break;
            case KEY_PLUS: size = size + 2;break;
            case KEY_MINUS: if (size>5) size = size - 2;break;
            case KEY_DOT: rotation = (rotation + 1) % 4;break;
            case KEY_COMA: rotation = (rotation + 3) % 4;break;
        }
    }
    getchar();
    return 0;
}

void gotoxy(short x, short y) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = { x, y };
    SetConsoleCursorPosition(hStdout, position);
}
