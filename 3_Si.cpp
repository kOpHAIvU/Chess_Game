#include "2_QuanCo.cpp"

class Si: public QuanCo {
	public:
		Si(int toado_x, int toado_y, int vitri_x, int vitri_y, int nguoichoi, string tenn): QuanCo(toado_x, toado_y, vitri_x, vitri_y, nguoichoi, tenn) {}
		int KiemTra(int vtm_x, int vtm_y, BanCo bc) {
			if(bc.lay_vtqc(vtm_x, vtm_y) != lay_nc() && vtm_x >= 3 && vtm_x <= 5 && ((lay_nc() == 1 && vtm_y <= 2) || (lay_nc() == 2 && vtm_y >= 7))) {
				if(abs(layvt_x() - vtm_x) == 1 && abs(layvt_y() - vtm_y) == 1)
						if(bc.lay_vtqc(vtm_x, vtm_y) != 0) 
                            return 2;
						else 
                            return 1;	
			} else
			    return 0;
			return 0;
		}

};