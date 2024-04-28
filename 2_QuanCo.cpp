#pragma once
#include "1_Setting.cpp"
class QuanCo {
	protected:
		int td_x, td_y;
		int vt_x, vt_y;
		int nc;
		string ten;
	public:
		QuanCo(int toado_x, int toado_y, int vitri_x, int vitri_y, int nguoichoi,string tenn) {
			td_x = toado_x;
			td_y = toado_y;
			vt_x = vitri_x;
			vt_y = vitri_y;
			nc   = nguoichoi;
			ten = tenn;
		}
		int lay_nc()   { return nc;  }
		int laytd_x () { return td_x;}
		int laytd_y () { return td_y;}
		string layten () { return ten; }
		QuanCo Gantd (int x, int y) {
			td_x = x;
			td_y = y;
			return *this;
		}
		int layvt_x () { return vt_x;}
		int layvt_y () { return vt_y;}
		QuanCo Ganvt (int x, int y) {
			vt_x = x;
			vt_y = y;
			return *this;
		}
		int KiemTraQC(int vitri_x, int vitri_y) {
			if(vt_x == vitri_x && vt_y == vitri_y) 
				return 1;
			else 
				return 0;
		}
		QuanCo DiChuyen (int toadomoi_x, int toadomoi_y, int vitrimoi_x, int vitrimoi_y, BanCo bc) {
				td_x = toadomoi_x;
				td_y = toadomoi_y;
				vt_x = vitrimoi_x;
				vt_y = vitrimoi_y;
			return *this;
		}
		QuanCo Xoa() {
			ten     = " ";
			nc = 0;
			return *this;
		}
		void InQuanCo() {
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			gotoxy(td_x, td_y);
			WCHAR chineseChar;
			if(nc == 1) {
				SetConsoleTextAttribute(hConsole, 2);
				if(ten == "Xe")  chineseChar = 0x4FE5;
				if(ten == "Phao")  chineseChar = 0x70AE;
				if(ten == "Ma")  chineseChar = 0x99AC;
				if(ten == "Tuong")  chineseChar = 0x5E25;
				if(ten == "Si")  chineseChar = 0x4ED5;
				if(ten == "Tinh")  chineseChar = 0x76F8;
				if(ten == "Chot")  chineseChar = 0x5175;
				WriteConsoleW(hConsole, &chineseChar, 1, NULL, NULL);
			}
			if(nc == 2) {
				SetConsoleTextAttribute(hConsole, 12);
				if(ten == "Xe")  chineseChar = 0x8ECA;
				if(ten == "Phao")  chineseChar = 0x7832;
				if(ten == "Ma")  chineseChar = 0x99AC;
				if(ten == "Tuong")  chineseChar = 0x5C07;
				if(ten == "Si")  chineseChar = 0x58EB;
				if(ten == "Tinh")  chineseChar = 0x8C61;
				if(ten == "Chot")  chineseChar = 0x5175;
				WriteConsoleW(hConsole, &chineseChar, 1, NULL, NULL);
			}
			SetConsoleTextAttribute(hConsole, 7);
		}
		virtual int KiemTra(int vtm_x, int vtm_y, BanCo bc) { return 0; }
};