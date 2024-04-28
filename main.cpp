#include "3_Chot.cpp"
#include "3_Ma.cpp"
#include "3_Phao.cpp"
#include "3_Si.cpp"
#include "3_Tinh.cpp"
#include "3_Tuong.cpp"
#include "3_Xe.cpp"

int KiemTra(QuanCo *q1, int vitrimoi_x, int vitrimoi_y, BanCo bc) {
	return q1->KiemTra(vitrimoi_x, vitrimoi_y, bc);
}

//Kiểm tra phím nhập vào là gì để thực hiện hiển thị tương ứng
void DiChuyen(char key, int &x, int &y, int &vt_x, int &vt_y) {
	if(key == 'w' || key == 72) {
		if(y > 1) {
			y -= 2;
			vt_y--;
		}
		gotoxy(x, y);
	}
	if(key == 's' || key == 80) {
		if(y < 18) {
			y += 2;
			vt_y++; 
		}
		gotoxy(x, y);
	}
	if(key == 'a' || key == 75) {
		if(x > 4) {
			x -= 4;
			vt_x--;
		}
		gotoxy(x, y);
	}
	if(key == 'd' || key == 77) {
		if(x < 31) {
			x += 4;
			vt_x++;
		}
		gotoxy(x, y);
	}
}

void ThongSo(int luot, int tt, int vt_x, int vt_y, BanCo bc, QuanCo *q = NULL) {
	gotoxy(40, 2);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "Luot di          : ";
	if(luot == 1) SetConsoleTextAttribute(hConsole, 2);
	else SetConsoleTextAttribute(hConsole, 12);
	cout << "Nguoi choi " << luot;
	SetConsoleTextAttribute(hConsole, 7);

	gotoxy(40, 5);
	cout << "Nhan p de chon quan co";

	gotoxy(40, 6);
	cout << "Quan co dang chon: ";
	if(q != NULL) cout << q->layten() << "    ";
	else		cout << "Khong";

	gotoxy(40, 3);
	cout << "TrangThai        : ";
	if(luot == 1) SetConsoleTextAttribute(hConsole, 2);
	else SetConsoleTextAttribute(hConsole, 12);
	if(tt == 0)	cout << "Chon quan co   ";
	if(tt == 1) cout << "Di chuyen      ";
	if(tt == 2) cout << "Di sai - Di lai";
	SetConsoleTextAttribute(hConsole, 7);
}

void GiaiPhongBoNho(QuanCo* q[], int size) {
    for (int i = 0; i < size; i++) {
        delete q[i];
    }
}
int main ()
{
	std::locale::global(std::locale("")); // Đặt locale cho đúng với môi trường
    std::wcout.imbue(std::locale()); // Đặt imbue để sử dụng locale cho wcout
	// Khoi tao ban dau
	BanCo bc;
	bc.InBanCo();

	//Khoi tao quan co cho nguoi choi 1
	QuanCo *q1[16];
	q1[0] = new Xe(2, 1, 0, 0, 1, "Xe"); q1[1] = new Xe(34, 1, 8, 0, 1, "Xe");
	q1[2] = new Ma(6, 1, 1, 0, 1, "Ma"); q1[3] = new Ma(30, 1, 7, 0, 1, "Ma");
	q1[4] = new Tinh(10, 1, 2, 0, 1, "Tinh"); q1[5] = new Tinh(26, 1, 6, 0, 1, "Tinh");
	q1[6] = new Si(14, 1, 3, 0, 1, "Si"); q1[7] = new Si(22, 1, 5, 0, 1, "Si");
	q1[8] = new Tuong(18, 1, 4, 0, 1, "Tuong");
	q1[9] = new Phao(6, 5, 1, 2, 1, "Phao"); q1[10] = new Phao(30, 5, 7, 2, 1, "Phao");
	q1[11] = new Chot(2, 7, 0, 3, 1, "Chot"); q1[12] = new Chot(10, 7, 2, 3, 1, "Chot"); q1[13] = new Chot(18, 7, 4, 3, 1, "Chot");
	q1[14] = new Chot(26, 7, 6, 3, 1, "Chot"); q1[15] = new Chot(34, 7, 8, 3, 1, "Chot");

	// Khoi tao quan co cho nguoi choi 2
	QuanCo *q2[16];
	q2[0] = new Xe(2, 19, 0, 9, 2, "Xe"); q2[1] = new Xe(34, 19, 8, 9, 2, "Xe");
	q2[2] = new Ma(6, 19, 1, 9, 2, "Ma"); q2[3] = new Ma(30, 19, 7, 9, 2, "Ma");
	q2[4] = new Tinh(10, 19, 2, 9, 2, "Tinh"); q2[5] = new Tinh(26, 19, 6, 9, 2, "Tinh");
	q2[6] = new Si(14, 19, 3, 9, 2, "Si"); q2[7] = new Si(22, 19, 5, 9, 2, "Si");
	q2[8] = new Tuong(18, 19, 4, 9, 2, "Tuong");
	q2[9] = new Phao(6, 15, 1, 7, 2, "Phao"); q2[10] = new Phao(30, 15, 7, 7, 2, "Phao");
	q2[11] = new Chot(2, 13, 0, 6, 2, "Chot"); q2[12] = new Chot(10, 13, 2, 6, 2, "Chot"); q2[13] = new Chot(18, 13, 4, 6, 2, "Chot");
	q2[14] = new Chot(26, 13, 6, 6, 2, "Chot"); q2[15] = new Chot(34, 13, 8, 6, 2, "Chot");

	// Khoi tao Ban co
	char key;
	int luot		= 1;
	int trangthai	= 0;
	int x = 2, y = 1, vt_x = 0, vt_y = 0;

	for(int i = 0; i <= 15; i++) {
		q1[i]->InQuanCo();
		q2[i]->InQuanCo();
	}
		
	ThongSo(luot, trangthai, vt_x, vt_y, bc);
	gotoxy(x, y);

	// Bat dau tro choi
	while(key = _getch()) {
		if(key == 27)
			break; // Bam escape de thoat
		if(key == 'p' && bc.lay_vtqc(vt_x, vt_y) == luot) {  
			int i = -1;
			trangthai = 1;
			for(i = 0; i < 15; i++) {
				if(luot == 1)
					if(q1[i]->KiemTraQC(vt_x, vt_y) == 1) 
						break;
				if(luot == 2)
					if(q2[i]->KiemTraQC(vt_x, vt_y) == 1) 
						break;
			}
			if(luot == 1)
				ThongSo(luot, trangthai, vt_x, vt_y, bc, q1[i]);
			else
				ThongSo(luot, trangthai, vt_x, vt_y, bc, q2[i]);
			gotoxy(x, y);
			while(key = _getch()) {
				if(key == 27) { 
					break;
				}
				trangthai = 0;
				DiChuyen(key, x, y, vt_x, vt_y);
				
				if(key == 'p' && i >= 0) {	
					if(luot == 1) {
						if(KiemTra(q1[i], vt_x, vt_y, bc) == 1) {
							bc.gan_vtqc(q1[i]->layvt_x(), q1[i]->layvt_y(), vt_x, vt_y, luot);
							q1[i]->DiChuyen(x, y, vt_x, vt_y, bc);
							luot = 2; trangthai = 0;
							clrscr();
							bc.InBanCo();	
						}
						if(KiemTra(q1[i], vt_x, vt_y, bc) == 2) {
							for (int j = 0; j <= 15; j++)
								if (q2[j]->layvt_x() == vt_x && q2[j]->layvt_y() == vt_y) {
									q2[j]->Xoa();
									break;
								}
							bc.gan_vtqc(q1[i]->layvt_x(), q1[i]->layvt_y(), vt_x, vt_y, luot);
							q1[i]->DiChuyen(x, y, vt_x, vt_y, bc);
							luot = 2; trangthai = 0;
							clrscr();
							bc.InBanCo();
						}
						i = -1;
						break;
					}	

					if(luot == 2) {
						if(KiemTra(q2[i], vt_x, vt_y, bc) == 1) {
							bc.gan_vtqc(q2[i]->layvt_x(), q2[i]->layvt_y(), vt_x, vt_y, luot);
							q2[i]->DiChuyen(x, y, vt_x, vt_y, bc);
							luot = 1; trangthai = 0;
							clrscr();
							bc.InBanCo();
						}
						if(KiemTra(q2[i], vt_x, vt_y, bc) == 2) {
							for(int j = 0; j <= 15; j++)
								if(q1[j]->layvt_x() == vt_x && q1[j]->layvt_y() == vt_y) {
									q1[j]->Xoa();
									break;
								}
							bc.gan_vtqc(q2[i]->layvt_x(), q2[i]->layvt_y(), vt_x, vt_y, luot);
							q2[i]->DiChuyen(x, y, vt_x, vt_y, bc);
							luot = 1; trangthai = 0;
							clrscr();
							bc.InBanCo();
						}
					}

					trangthai = 2;
					i = -1;
					break;
				} 
				if (luot == 1)
					ThongSo(luot, trangthai, vt_x, vt_y, bc, q1[i]);
				if (luot == 2)
					ThongSo(luot, trangthai, vt_x, vt_y, bc, q2[i]);
				gotoxy(x, y);
			}
		}

		DiChuyen(key, x, y, vt_x, vt_y);
		for(int i = 0; i <= 15; i++) {
			if(q1[i]->layten() != " ")
				q1[i]->InQuanCo();
			if(q2[i]->layten() != " ")
				q2[i]->InQuanCo();
		}
			
		if(q1[8]->laytd_x() == q2[8]->laytd_x()) {  //Tướng đối tướng
			int dem = 0;
			for(int i = 0; i <= 15; i++)
				if((q1[i]->laytd_x() == q1[8]->laytd_x() || q2[i]->laytd_x() == q1[8]->laytd_x()) && i != 8) 
					if((q1[i]->laytd_y() > q1[8]->laytd_y() && q1[i]->laytd_y() < q2[8]->laytd_y()) || (q2[i]->laytd_y() > q1[8]->laytd_y() && q2[i]->laytd_y() < q2[8]->laytd_y()))
						dem++;
			if(dem == 0) {
				if(luot == 1) 
					q2[8]->Xoa();
				else if(luot == 2)
						q1[8]->Xoa();
			}
		}
		
		if(q1[8]->layten() == " " || q1[8]->lay_nc() == 0) { 
			gotoxy(40, 10);
			cout << "Nguoi choi 2 thang";
			break;
		}

		if(q2[8]->layten() == " "|| q2[8]->lay_nc() == 0) {
			gotoxy(40, 10);
			cout << "Nguoi choi 1 thang";
			break;
		}

		if(luot == 1)
			trangthai = 0;
		ThongSo(luot, trangthai, vt_x, vt_y, bc);
		gotoxy(x, y);
	}
	gotoxy(9, 10);
	cout << "Tro choi ket thuc";
	_getch();
	GiaiPhongBoNho(q1, 16);
	GiaiPhongBoNho(q2, 16);
	exit(1);	

	return 0;
}