#include "2_QuanCo.cpp"

class Xe: public QuanCo {
	public:
		Xe(int toado_x, int toado_y, int vitri_x, int vitri_y, int nguoichoi, string tenn): QuanCo(toado_x, toado_y, vitri_x, vitri_y, nguoichoi, tenn) {}
		int KiemTra(int vtm_x, int vtm_y, BanCo bc) {
			int i;
			if(bc.lay_vtqc(vtm_x, vtm_y) != lay_nc()) {
				if(vtm_x > layvt_x() && vtm_y == layvt_y()) {
					for (i = layvt_x() + 1; i < vtm_x; i++)
						if (bc.lay_vtqc(i,vtm_y) != 0) 
                            return 0;
				} 
                else 
                    if(vtm_x < layvt_x() && vtm_y == layvt_y()) {
					    for(i = layvt_x() - 1;i > vtm_x; i--) 
						    if (bc.lay_vtqc(i,vtm_y) != 0) 
                                return 0;
				    }
                    else 
                        if(vtm_x == layvt_x() && vtm_y > layvt_y()) {
                            for(i = layvt_y() + 1;i < vtm_y; i++) 
                                if (bc.lay_vtqc(i,vtm_y) != 0) 
									return 0;
                        }
				        else 
                            if(vtm_x == layvt_x() && vtm_y < layvt_y()) {
                                for(i = layvt_y() - 1;i > vtm_y; i--) 
                                    if (bc.lay_vtqc(i,vtm_y) != 0) 
                                        return 0;
				            }
			if(bc.lay_vtqc(vtm_x,vtm_y) != 0) 
				return 2;
			else    
				return 1;
			} else  return 0;
			return 0;
		}
};