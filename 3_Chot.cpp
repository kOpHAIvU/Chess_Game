#include "2_QuanCo.cpp"

class Chot: public QuanCo {
	public:
		Chot(int toado_x, int toado_y, int vitri_x, int vitri_y, int nguoichoi, string tenn): QuanCo(toado_x, toado_y, vitri_x, vitri_y, nguoichoi, tenn) {}
		int KiemTra(int vtm_x, int vtm_y, BanCo bc) {
			if(bc.lay_vtqc(vtm_x, vtm_y) != lay_nc()) {		//Kiểm tra để nước đi team mình không tự ăn team mình	
				if((layvt_x() - vtm_x == -1 || layvt_x() - vtm_x == 1) && layvt_y() == vtm_y)
					  //Trường hợp team 1 qua nước           trường hợp team 2 qua nước
					if(lay_nc() == 1 && (layvt_y() >= 5) || (lay_nc() == 2 && layvt_y() <= 4) ) 
						if(bc.lay_vtqc(vtm_x, vtm_y) != 0) 
                            return 2;						//Trường hợp di chuyển ăn quân team bạn
						else 
                            return 1;						//Chỉ có di chuyển

				//Trường hợp chưa qua nước
				if(layvt_x() == vtm_x && (layvt_y() - vtm_y == 1 || layvt_y() - vtm_y == -1))
					if(lay_nc() == 1 || lay_nc() == 2)
						if(bc.lay_vtqc(vtm_x, vtm_y) != 0) 
                            return 2;
						else 
                            return 1;
			} else
				return 0;
			return 0;
		}
};