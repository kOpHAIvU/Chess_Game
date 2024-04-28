#include "2_QuanCo.cpp"

class Phao: public QuanCo {
	public:
		Phao(int toado_x, int toado_y, int vitri_x, int vitri_y, int nguoichoi, string tenn): QuanCo(toado_x, toado_y, vitri_x, vitri_y, nguoichoi, tenn) {}
		int KiemTra(int vtm_x, int vtm_y, BanCo bc) {
			int i, soQuanCoTrenDuongDi = 0;
			if(bc.lay_vtqc(vtm_x, vtm_y) != lay_nc()) {
				//Đang kiểm tra xem số lượng quân chặn Pháo có lớn hơn 2 không
				//Trường hợp Pháo di chuyển tiến theo trục x
				if(vtm_x > layvt_x() && vtm_y == layvt_y()) {
					for(i = layvt_x() + 1; i < vtm_x ;i++) 
						if (bc.lay_vtqc(i, vtm_y) == 1 || bc.lay_vtqc(i, vtm_y) == 2) {
							soQuanCoTrenDuongDi++;	
							if(soQuanCoTrenDuongDi >= 2)
                                return 0;
						}
				}
				else 
					//Trường hợp Pháo di chuyển lùi theo trục x
                    if(vtm_x < layvt_x() && vtm_y == layvt_y()) {
                        for(i=layvt_x() - 1;i > vtm_x;i--) 
                            if (bc.lay_vtqc(i, vtm_y) == 1 || bc.lay_vtqc(i, vtm_y) == 2) {
                                soQuanCoTrenDuongDi++;	 
                                if(soQuanCoTrenDuongDi >= 2)
                                    return 0;
                            }
				    }
				    else 
						//Trường hợp Pháo di chuyển tiến theo trục y
                        if(vtm_x == layvt_x() && vtm_y > layvt_y()) {
                            for(i = layvt_y() + 1;i < vtm_y; i++) 
                                if (bc.lay_vtqc(vtm_x, i) == 1 || bc.lay_vtqc(vtm_x, i) == 2) {
                                    soQuanCoTrenDuongDi++;	
                                    if(soQuanCoTrenDuongDi >= 2)
                                        return 0;
                                }
                        }
				        else 
							//Trường hợp Pháo di chuyển lùi theo trục y
                            if(vtm_x == layvt_x() && vtm_y < layvt_y()) {
                                for(i = layvt_y() - 1;i > vtm_y; i--) 
                                    if (bc.lay_vtqc(vtm_x, i) == 1 || bc.lay_vtqc(vtm_x, i) == 2) {
                                        soQuanCoTrenDuongDi++;	
                                        if(soQuanCoTrenDuongDi >= 2)
                                            return 0;
                                    }
                            }
			
			if(soQuanCoTrenDuongDi == 1) {		//Ăn team bạn
				if(bc.lay_vtqc(vtm_x,vtm_y) != 0)	
					return 2;
			} else {
				if(bc.lay_vtqc(vtm_x,vtm_y) != 0)	//Không thể ăn team bạn vì k có quân chắn
					return 0;
				else return 1;
			}
			} else
				return 0;
			return 0;
		}
};