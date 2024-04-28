#include "2_QuanCo.cpp"

class Tinh: public QuanCo {
	public:
		Tinh(int toado_x, int toado_y, int vitri_x, int vitri_y, int nguoichoi, string tenn): QuanCo(toado_x, toado_y, vitri_x, vitri_y, nguoichoi, tenn) {}
		
		int KiemTra(int vtm_x,int vtm_y, BanCo bc) {
			if(bc.lay_vtqc(vtm_x, vtm_y) != lay_nc() &&  ((lay_nc() == 1 && vtm_y <= 4) || (lay_nc() == 2 && vtm_y >= 5))) {
														//Đảm bảo việc nó không qua nước
				if(layvt_x() - vtm_x == -2 && layvt_y() - vtm_y == -2)
					if(bc.lay_vtqc(layvt_x() + 1, layvt_y() + 1) == 0)
						if(bc.lay_vtqc(vtm_x,vtm_y) != 0) 
                            return 2;
						else    
                            return 1;
				
				if(layvt_x() - vtm_x == 2 && layvt_y() - vtm_y == 2)
					if(bc.lay_vtqc(layvt_x() - 1, layvt_y() - 1) == 0)
						if(bc.lay_vtqc(vtm_x,vtm_y) != 0) 
                            return 2;
						else    
                            return 1;	
				
				if(layvt_x() - vtm_x == -2 && layvt_y() - vtm_y == 2)
					if(bc.lay_vtqc(layvt_x() + 1, layvt_y() - 1) == 0)
						if(bc.lay_vtqc(vtm_x, vtm_y) != 0) 
                            return 2;
						else 
                            return 1;	

				if(layvt_x() - vtm_x == 2 && layvt_y() - vtm_y == -2)
					if(bc.lay_vtqc(layvt_x()-1,layvt_y() + 1) == 0)
						if(bc.lay_vtqc(vtm_x, vtm_y) != 0) 
                            return 2;
						else 
                            return 1;	
			} else
				return 0;
			return 0;
        }
};