#include "ThuVienCuaToi.h"

bool laNamNhuan(int nam)
{
	if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
	{
		return true;
	}
	return false;
}

int tinhSoNgayTrongThang(int thang, int nam)
{
	int ngayTraVe;

	switch (thang)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: 
		ngayTraVe = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11: 
		ngayTraVe = 30;
		break;
	case 2:
		if (laNamNhuan(nam))
		{
			ngayTraVe = 29;
		}
		else
		{
			ngayTraVe = 28;
		}
		break;
	}

	return ngayTraVe;
}

bool laNgayHopLe(int ngay, int thang, int nam)
{
	if (nam < 0)
	{
		return false;
	}

	if (thang < 1 || thang > 12)
	{
		return false; 
	}
	
	if (ngay < 1 || ngay > tinhSoNgayTrongThang(thang, nam))
	{
		return false;
	}

	return true; 
}

int getNgay(NgayThang date) {
	return date.ngay;
}
void setNgay(NgayThang &date) {
	scanf("%d", &date.ngay);
}

int getThang(NgayThang date) {
	return date.thang;
}
void setThang(NgayThang &date) {
	scanf("%d", &date.thang);
}

int getNam(NgayThang date) {
	return date.nam;
}
void setNam(NgayThang &date) {
	scanf("%d", &date.nam);
}

char *getTenVaccine(Vaccine *vx) {
	return vx->tenVaccine;
}
void setTenVaccine(Vaccine &vx) {
	fflush(stdin);
	gets(vx.tenVaccine);
}

char *getTenBenhNhan(BenhNhan *bn) {
	return bn->hoVaTen;
}
void setTenBenhNhan(BenhNhan &bn) {
	fflush(stdin);
	gets(bn.hoVaTen);
}

char *getDanToc(BenhNhan *bn) {
	return bn->danToc;
}
void setDanToc(BenhNhan &bn) {
	fflush(stdin);
	gets(bn.danToc);
}

char *getSDT(BenhNhan *bn) {
	return bn->SDT;
}
void setSDT(BenhNhan &bn) {
	scanf("%s", &bn.SDT);
}

char *getCCCD_CMND(BenhNhan *bn) {
	return bn->CCCD_CMND;
}
void setCCCD_CMND(BenhNhan &bn) {
	scanf("%s", &bn.CCCD_CMND);
}

char *getNgheNghiep(BenhNhan *bn) {
	return bn->ngheNghiep;
}
void setNgheNghiep(BenhNhan &bn) {
	fflush(stdin);
	gets(bn.ngheNghiep);
}

char *getBhyt(BenhNhan *bn) {
	return bn->soTheBHYT;
} 
void setBhyt(BenhNhan &bn) {
	fflush(stdin);
	gets(bn.soTheBHYT);
}

char *getNoiThuongTru(BenhNhan *bn) {
	return bn->noiThuongTru;
}
void setNoiThuongTru(BenhNhan &bn) {
	fflush(stdin);
	gets(bn.noiThuongTru);
} 

char *getKhoaDieuTri(BenhNhan *bn) {
	return bn->khoaDieuTri;
}
void setKhoaDieuTri(BenhNhan &bn) {
	fflush(stdin);
	gets(bn.khoaDieuTri);
}

int getSoGiuong(BenhNhan bn) {
	return bn.soGiuong;
}
void setSoGiuong(BenhNhan &bn) {
	scanf("%d", &bn.soGiuong);
}

int getMucDo(BenhNhan bn) {
	return bn.mucDo;
}
void setMucDo(BenhNhan &bn) {
	scanf("%d", &bn.mucDo);
}

void nhapBenhNhap(BenhNhan &bn) {
	do {
		printf("- Nhap ho va ten: ");
		setTenBenhNhan(bn);
		if(strlen(getTenBenhNhan(&bn)) > 25 || strlen(getTenBenhNhan(&bn)) < 1) {
			printf("Ten khong hop le vui long nhap lai !!!\n");
		}
	} while(strlen(getTenBenhNhan(&bn)) > 25 || strlen(getTenBenhNhan(&bn)) < 1);
		vietHoaChuCaiDau(&bn);
	do {
		printf("- Nhap ngay thang nam sinh: ");
		setNgay(bn.ngaySinh);
		setThang(bn.ngaySinh);
		setNam(bn.ngaySinh);
		if(!laNgayHopLe(getNgay(bn.ngaySinh), getThang(bn.ngaySinh), getNam(bn.ngaySinh))) {
			printf("Ngay nhap vao khong hop le vui long nhap lai !!!\n");
		}
	} while(!laNgayHopLe(getNgay(bn.ngaySinh), getThang(bn.ngaySinh), getNam(bn.ngaySinh)));
	
	do {
		printf("- Dan toc: ");
		setDanToc(bn);
		if(strlen(getDanToc(&bn)) > 10 || strlen(getDanToc(&bn)) < 1) {
			printf("Dan toc khong hop len vui long nhap lai !!!\n");
		} 
	} while(strlen(getDanToc(&bn)) > 10 || strlen(getDanToc(&bn)) < 1);
		bool check;
	do{
		printf("- Nhap so dien thoai: ");
		setSDT(bn);
		for(int i=0;i<strlen(getSDT(&bn));i++){
			check = false;
			if((bn.SDT[i]<48 || bn.SDT[i]>57) || strlen(bn.SDT) != 10){
				printf("so dien thoai khong hop le\n");
				check = true;
				break;
			}
		}
	}while(check);
	
	do{
		printf("- Nhap so can cuoc cong dan: ");
		setCCCD_CMND(bn);
		for(int i=0;i<strlen(getSDT(&bn));i++){
			check = false;
			if((bn.SDT[i] < 48 || bn.SDT[i] > 57) || strlen(bn.CCCD_CMND) != 12){
				printf("so CCCD khong hop le\n");
				check = true;
				break;
			}
		}
	}while(check);
	
	do {
		printf("- Nhap nghe nghiep: ");
		setNgheNghiep(bn);
		if(strlen(getNgheNghiep(&bn)) > 15 || strlen(getNgheNghiep(&bn)) < 1) {
			printf("Nghe nghiep khong hop le vui long nhap lai !!! \n");
		}
	} while(strlen(getNgheNghiep(&bn)) > 15 || strlen(getNgheNghiep(&bn)) < 1);
	
	do {
		printf("- Nhap so the bao hieu y te (Truong hop khong co nhap 0): ");
		setBhyt(bn);
		if(strlen(getBhyt(&bn)) > 15 || strlen(getBhyt(&bn)) < 1) {
			printf("So the bao hiem y te khong hop le vui long nhap lai !!!|n");
		}
	} while(strlen(getBhyt(&bn)) > 15 || strlen(getBhyt(&bn)) < 1);
	
	do {
		printf("- Nhap dia chi thuong tru: ");
		setNoiThuongTru(bn);
		if(strlen(getNoiThuongTru(&bn)) > 25 || strlen(getNoiThuongTru(&bn)) < 1) {
			printf("Noi thuong tru khong hop le vui long nhap lai !!!\n");
		}
	} while(strlen(getNoiThuongTru(&bn)) > 25 || strlen(getNoiThuongTru(&bn)) < 1);
	
	do {
		printf("- Nhap khoa dieu tri: ");
		setKhoaDieuTri(bn);
		if(strlen(getKhoaDieuTri(&bn)) > 25 || strlen(getKhoaDieuTri(&bn)) < 1) {
			printf("Khoa dieu tri khong hop le vui long nhap lai !!!\n");
		}
	} while(strlen(getKhoaDieuTri(&bn)) > 25 || strlen(getKhoaDieuTri(&bn)) < 1);
	
	printf("- Nhap so giuong: ");
	setSoGiuong(bn);
	
	do {
		printf("- Nhap ngay thang nam nhap vien: ");
		setNgay(bn.ngayNhapVien);
		setThang(bn.ngayNhapVien);
		setNam(bn.ngayNhapVien);
		if(!laNgayHopLe(getNgay(bn.ngayNhapVien), getThang(bn.ngayNhapVien), getNam(bn.ngayNhapVien))) {
			printf("Ngay nhap vao khong hop le vui long nhap lai !!!\n");
		}
	} while(!laNgayHopLe(getNgay(bn.ngayNhapVien), getThang(bn.ngayNhapVien), getNam(bn.ngayNhapVien)));
	
	do {
		printf("- Muc do nhap vien: ");
		printf("\n\t1. Muc do nhe");
		printf("\n\t2. Muc do trung binh");
		printf("\n\t3. Muc do nang");
		printf("\nNhap lua lua chon: ");
		setMucDo(bn);
		if(getMucDo(bn) != 1 && getMucDo(bn) != 2 && getMucDo(bn) != 3) {
			printf("Muc do khong hop le vui long nhap lai !!!\n");
		}
	} while(getMucDo(bn) != 1 && getMucDo(bn) != 2 && getMucDo(bn) != 3);

	printf("* THONG TIN VACCCINE (Chua tiem nhap ten 0 ngay 1/1/1)\n");
	printf("\t- Mui 1\n");
	do {
		printf("\t\t+ Nhap ten vaccine: ");
		setTenVaccine(bn.mui_1);
		if(strlen(getTenVaccine(&bn.mui_1)) > 15 || strlen(getTenVaccine(&bn.mui_1)) < 1) {
			printf("Ten vaccine khong hop le vui long nhap lai !!!\n");
		} 
	} while(strlen(getTenVaccine(&bn.mui_1)) > 15 || strlen(getTenVaccine(&bn.mui_1)) < 1);
	do {
		printf("\t\t+ Ngay tiem: ");
		setNgay(bn.mui_1.ngayTiem);
		setThang(bn.mui_1.ngayTiem);
		setNam(bn.mui_1.ngayTiem);
		if(!laNgayHopLe(getNgay(bn.mui_1.ngayTiem), getThang(bn.mui_1.ngayTiem), getNam(bn.mui_1.ngayTiem))) {
			printf("Ngay khong hop le vui long nhap lai !!!\n");
		}
	} while (!laNgayHopLe(getNgay(bn.mui_1.ngayTiem), getThang(bn.mui_1.ngayTiem), getNam(bn.mui_1.ngayTiem)));
	
	printf("\t- Mui 2\n");
	do {
		printf("\t\t+ Nhap ten vaccine: ");
		setTenVaccine(bn.mui_2);
		if(strlen(getTenVaccine(&bn.mui_2)) > 15 || strlen(getTenVaccine(&bn.mui_2)) < 1) {
			printf("Ten vaccine khong hop le vui long nhap lai !!!\n");
		} 
	} while(strlen(getTenVaccine(&bn.mui_2)) > 15 || strlen(getTenVaccine(&bn.mui_2)) < 1);
	do {
		printf("\t\t+ Ngay tiem: ");
		setNgay(bn.mui_2.ngayTiem);
		setThang(bn.mui_2.ngayTiem);
		setNam(bn.mui_2.ngayTiem);
		if(soSanhNgay(bn.mui_1.ngayTiem, bn.mui_2.ngayTiem)){
			printf("Ngay tiem mui 2 tai sao lai truoc mui 1??, yeu cau nhap lai.\n");
		}
		if(!laNgayHopLe(getNgay(bn.mui_2.ngayTiem), getThang(bn.mui_2.ngayTiem), getNam(bn.mui_2.ngayTiem))) {
			printf("Ngay khong hop le vui long nhap lai !!!\n");
		}
	} while (!laNgayHopLe(getNgay(bn.mui_2.ngayTiem), getThang(bn.mui_2.ngayTiem), getNam(bn.mui_2.ngayTiem)) || soSanhNgay(bn.mui_1.ngayTiem,bn.mui_2.ngayTiem));
	
	printf("\t- Mui 3\n");
	do {
		printf("\t\t+ Nhap ten vaccine: ");
		setTenVaccine(bn.mui_3);
		if(strlen(getTenVaccine(&bn.mui_3)) > 15 || strlen(getTenVaccine(&bn.mui_3)) < 1) {
			printf("Ten vaccine khong hop le vui long nhap lai !!!\n");
		} 
	} while(strlen(getTenVaccine(&bn.mui_3)) > 15 || strlen(getTenVaccine(&bn.mui_3)) < 1);
	do {
		printf("\t\t+ Ngay tiem: ");
		setNgay(bn.mui_3.ngayTiem);
		setThang(bn.mui_3.ngayTiem);
		setNam(bn.mui_3.ngayTiem);
		if(!laNgayHopLe(getNgay(bn.mui_3.ngayTiem), getThang(bn.mui_3.ngayTiem), getNam(bn.mui_3.ngayTiem))) {
			printf("Ngay khong hop le vui long nhap lai !!!\n");
		}
		if(soSanhNgay(bn.mui_2.ngayTiem, bn.mui_3.ngayTiem)){
			printf("Ngay tiem mui 3 tai sao lai truoc mui 2??, yeu cau nhap lai.\n");
		}
	} while (!laNgayHopLe(getNgay(bn.mui_3.ngayTiem), getThang(bn.mui_3.ngayTiem), getNam(bn.mui_3.ngayTiem)) || soSanhNgay(bn.mui_2.ngayTiem, bn.mui_3.ngayTiem));
}

void xuatBenhNhan(BenhNhan bn) {
	printf("%-25s", getTenBenhNhan(&bn));
	printf("%-2d/%-2d/%-4d\t", getNgay(bn.ngaySinh), getThang(bn.ngaySinh), getNam(bn.ngaySinh));
	printf("%-10s\t", getDanToc(&bn));
	printf("%-10s\t", getSDT(&bn));
	printf("%-15s", getCCCD_CMND(&bn));
	printf("%-15s", getNgheNghiep(&bn));
	printf("%-15s", getBhyt(&bn));
	printf("%-25s", getNoiThuongTru(&bn));
	printf("%-15s\t", getKhoaDieuTri(&bn));
	printf("%-10d\t", getSoGiuong(bn));
	printf("%-2d/%-2d/%-4d\t\t", getNgay(bn.ngayNhapVien), getThang(bn.ngayNhapVien), getNam(bn.ngayNhapVien));
	printf("%-10d\n", getMucDo(bn));
	
}

void nhapDanhSachBenhNhan(BenhNhan *bn, int soLuong) {
	for(int i = 0; i < soLuong; i++) {
		textcolor(1);
		if(i % 2 == 0) {
			textcolor(4);
		}
		printf("===== NHAP THONG TIN BENH NHAN THU %d =====\n", i+1);
		nhapBenhNhap(bn[i]);
	}
}


void xuatDanhSachBenhNhan(BenhNhan *bn, int soLuong) {
	textcolor(1);
	printf("\t\t\t\t\t\t\t\t\t\t\t========== DANH SACH BENH NHAN ==========\n");
	printf("%-25s", "Ho va ten");
	printf("%-10s\t", "Ngay sinh");
	printf("%-10s\t", "Dan toc");
	printf("%-10s\t", "SDT");
	printf("%-15s", "So CMND/CCCD");
	printf("%-15s", "Nghe nghiep");
	printf("%-15s", "So BHYT");
	printf("%-25s", "Noi thuong tru");
	printf("%-15s\t", "Khoa dieu tri");
	printf("%-10s\t", "So giuong");
	printf("%-15s\t\t", "Ngay nhap vien");
	printf("%-10s\n", "Muc do");
	for(int i = 0; i < soLuong; i++) {
		textcolor(31);
		if(i % 2 == 0) {
			textcolor(207);
		}
		xuatBenhNhan(bn[i]);
	}
} 

void xuatThongTinVaccine(BenhNhan bn) {
	
	printf("\t%-25s", getTenBenhNhan(&bn));
	printf("\t%-15s", getTenVaccine(&bn.mui_1));
	printf("\t\t%-2d/%-2d/%-4d", getNgay(bn.mui_1.ngayTiem), getThang(bn.mui_1.ngayTiem), getNam(bn.mui_1.ngayTiem));
	
	printf("\t\t%-15s", getTenVaccine(&bn.mui_2));
	printf("\t\t%-2d/%-2d/%-4d", getNgay(bn.mui_2.ngayTiem), getThang(bn.mui_2.ngayTiem), getNam(bn.mui_2.ngayTiem));
	
	printf("\t\t\t%-15s", getTenVaccine(&bn.mui_3));
	printf("\t\t%-2d/%-2d/%-4d\t\t\t\t", getNgay(bn.mui_3.ngayTiem), getThang(bn.mui_3.ngayTiem), getNam(bn.mui_3.ngayTiem));
	
}

void xuatDanhSachVaccine(BenhNhan *bn, int soLuong) {
	textcolor(1);
	printf("\t\t\t\t\t\t\t\t ========== DANH SACH THONG TIN VACCINE CUA BENH NHAN ==========\n");
	printf("\t%-25s", "Ho va ten");
	printf("\t%-15s", "Mui 1");
	printf("\t\t%-15s", "Ngay tiem mui 1");
	printf("\t\t%-15s", "Mui 2");
	printf("\t\t%-15s", "Ngay tiem mui 2");
	printf("\t\t\t%-15s", "Mui 3");
	printf("\t\t%-15s\t\t\t\t\n", "Ngay tiem mui 3");
	for(int i = 0; i < soLuong; i++) {
		textcolor(31);
		if(i % 2 == 0) {
			textcolor(207);
		}
		xuatThongTinVaccine(bn[i]);
		printf("\n");
	}
}
bool soSanhNgay(NgayThang ngay_1, NgayThang ngay_2) {
	if(ngay_1.nam > ngay_2.nam) {
		return true;
	}
 
	if(ngay_1.nam == ngay_2.nam) {
		if(ngay_1.thang > ngay_2.thang) {
			return true;
		}
 
		if(ngay_1.thang == ngay_2.thang) {
			if(ngay_1.ngay > ngay_2.ngay) {
				return true;
			}
		}
	}
 
	return false;
}


void themDau(BenhNhan *bn, int &soLuong){
	BenhNhan giaTriThem;
	soLuong++;
	for(int i=soLuong;i>0;i--){
		bn[i]=bn[i-1];
	}
	nhapBenhNhap(giaTriThem);
	bn[0] = giaTriThem;
}

void themCuoi(BenhNhan *bn, int &soLuong){
	BenhNhan giaTriThem;
	soLuong++;
	nhapBenhNhap(giaTriThem);
	bn[soLuong - 1] = giaTriThem;
}

void themBatKy(BenhNhan *bn, int &soLuong){
	int x;
	do{
		printf("\nnhap vi tri muon them:");
		scanf("%d", &x);
		if(x<0||x>=soLuong){
			printf("vi tri muon them nam ngoai danh sach\n");
		}
	}while(x<0||x>=soLuong);
	
	if(x == 0) {
		themDau(bn, soLuong);
		return;
	}
	
	if(x == soLuong - 1) {
		themCuoi(bn, soLuong);
		return;
	}
	BenhNhan giaTriThem;
	soLuong++;
	for(int i = soLuong-1; i>x;i--){
		bn[i] = bn[i-1];
	}
	bn[x] = giaTriThem;
}

int soNgayChenhLech(NgayThang ngay_1, NgayThang ngay_2) {
	return fabs(tinhSoNgayTrongThang(ngay_1.thang, ngay_1.nam) + ngay_1.ngay);
}

void xoaDau(BenhNhan *bn, int &soLuong) {
	for(int i = 0; i < soLuong - 1; i++) {
		bn[i] = bn[i + 1];
	}
	soLuong--;
}

void xoaCuoi(BenhNhan *bn, int &soLuong) {
	soLuong--;
} 

void xoaBatKy(BenhNhan *bn, int &soLuong){
	int x;
	do{
		printf("\nnhap vi tri muon xoa:");
		scanf("%d", &x);
		if(x<0||x>=soLuong){
			printf("vi tri muon xoa nam ngoai danh sach\n");
		}
	}while(x<0||x>=soLuong);
	
	if(x == 0) {
		xoaDau(bn, soLuong);
		return;
	}
	if(x == soLuong - 1) {
		xoaCuoi(bn, soLuong);
		return;
	}

	for(int i = x; i < soLuong - 1; i++) {
		bn[i] = bn[i + 1];
	}
	soLuong--;
}

void vietHoachucai(char *x){
	if(*x<=122 && *x>=97)
		*x = *x - 32;
}

void vietThuongChuCai(char *x){
	if(*x>=65 && *x<=90)
		*x = *x + 32;
}

void vietHoaChuCaiDau(BenhNhan *bn){
	for(int i=0;i<strlen(bn->hoVaTen);i++){
		if(i==0 || (i>0 && bn->hoVaTen[i-1]==32)){
			vietHoachucai((bn->hoVaTen + i));
		}
		else
			vietThuongChuCai((bn->hoVaTen +i));
	}
}
void sapXepBenhNhanTheoTen(BenhNhan *bn, int &soLuong) {
	for(int i = 0; i < soLuong - 1; i ++) {
		for(int j = i + 1; j < soLuong; j++) {
			if(strcmp((bn->hoVaTen + i) , (bn->hoVaTen + j))>0){
				BenhNhan c = bn[i];
				bn[i] = bn[j];
				bn[j] = c;
			}
		}
	}
}





