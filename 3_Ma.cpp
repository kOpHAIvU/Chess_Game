#include "2_QuanCo.cpp"

class Ma: public QuanCo {
	public:
		Ma(int toado_x, int toado_y, int vitri_x, int vitri_y, int nguoichoi, string tenn): QuanCo(toado_x, toado_y, vitri_x, vitri_y, nguoichoi, tenn) {}
		int KiemTra(int vtm_x, int vtm_y, BanCo bc) {
			if(bc.lay_vtqc(vtm_x, vtm_y) != lay_nc()) {
				if(abs(layvt_x() - vtm_x) == 1 && abs(layvt_y() - vtm_y) == 2)
					//Kiểm tra xem có quân nào chặn ở trục y không
					if(bc.lay_vtqc(layvt_x(), layvt_y() - 1) == 0 || bc.lay_vtqc(layvt_x(), layvt_y() + 1) == 0)
						if(bc.lay_vtqc(vtm_x,vtm_y) != 0) 
                            return 2;
						else 
                            return 1;	

				if(abs(layvt_x() - vtm_x) == 2 && abs(layvt_y() - vtm_y) == 1)
					//Kiểm tra xem có quân nào chặn ở trục x không
					if(bc.lay_vtqc(layvt_x() - 1,layvt_y()) == 0 || bc.lay_vtqc(layvt_x() + 1,layvt_y()) == 0)
						if(bc.lay_vtqc(vtm_x, vtm_y) != 0) 
                            return 2;
						else
                            return 1;	
			} else
				return 0;
			return 0;
		}
};