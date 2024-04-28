#pragma once
#include <windows.h>
#include "math.h"
#include <iostream>
#include "conio.h"
#include "stdio.h"
using namespace std;


class QuanCo;

void clrscr(void) {
    CONSOLE_SCREEN_BUFFER_INFO  csbiInfo;                  
    HANDLE  hConsoleOut;
    COORD   Home = {0,0};
    DWORD   dummy;

    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

    FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
    csbiInfo.dwCursorPosition.X = 0;                         
    csbiInfo.dwCursorPosition.Y = 0;                        
    SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);   
}

// void gotoxy(short x, short y) {
//     HANDLE hConsoleOutput;
//     COORD Cursor_an_Pos = {x, y};
//     hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//     SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
// }
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Khởi tạo bàn cờ
class BanCo {
	protected:
		int vtqc[9][10];
	public:
		BanCo() {
			for(int i = 0 ; i < 9 ; i++) 
				for(int j = 0; j < 10 ; j++) 
					vtqc[i][j] = 0;
			for (int i = 0; i < 9 ; i++) {
				vtqc[i][0] = 1;
				vtqc[i][9] = 2;
			}
			for (int i = 0; i <= 8; i = i + 2) {
				vtqc[i][3] = 1;
				vtqc[i][6] = 2;
			}
			vtqc[1][2] = 1;
			vtqc[7][2] = 1;
			vtqc[1][7] = 2;
			vtqc[7][7] = 2;
		}
		int lay_vtqc(int vitri_x, int vitri_y) {
			return vtqc[vitri_x][vitri_y];
		}
		BanCo gan_vtqc(int vt_x, int vt_y, int vitrimoi_x, int vitrimoi_y, int luot) {
			vtqc[vt_x][vt_y] = 0;
			if(luot == 1)
				vtqc[vitrimoi_x][vitrimoi_y] = 1;
			else 
				vtqc[vitrimoi_x][vitrimoi_y] = 2;
			return *this;
		}
		void InBanCo() {
			cout << endl;
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 8);
			for(int i = 0; i < 19 ; i++) {
				if(i % 2 == 0) {
					cout << "  " ;
					for(int j = 0; j < 8 ; j++)
						cout << " ---" ; 
					cout << " " <<  endl;
				} else {
					cout << "  " ;
					for(int j = 0;j < 9;j++)
						if(i == 9)
							if(j == 0 || j == 8)    
                                cout << "|   ";
							else   
                                cout << "    ";
						else 
                            cout << "|   ";
					cout << endl;
				}
			}
			gotoxy(16, 2);	cout << "\\";
			gotoxy(20, 2);	cout << "/";
			gotoxy(16, 4);	cout << "/";
			gotoxy(20, 4);	cout << "\\";
			for(int i = 1; i <= 9; i += 4)
				for(int j = 1; j <= 5; j += 2) {
					gotoxy(13 + i, j);
					cout << "+";
				}
			gotoxy(16, 16);	cout << "\\";
			gotoxy(20, 16);	cout << "/";
			gotoxy(16, 18);	cout << "/";
			gotoxy(20, 18);	cout << "\\";
			for(int i = 1; i <= 9; i += 4)
				for(int j = 1; j <= 5; j += 2) {
					gotoxy(13 + i, 14 + j);
					cout << "+";
				}
			
			SetConsoleTextAttribute(hConsole, 7);
		}
};