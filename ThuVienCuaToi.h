#include "DoHoa.h"

typedef struct {
	int ngay;
	int thang;
	int nam;
} NgayThang;

typedef struct {
	NgayThang ngayTiem;
	char tenVaccine[15];
} Vaccine;

typedef struct {
	char hoVaTen[25];
	NgayThang ngaySinh;
	char danToc[10];
	char SDT[10];
	char CCCD_CMND[12];
	char ngheNghiep[15];
	char soTheBHYT[15];
	char noiThuongTru[25];
	char khoaDieuTri[15];
	int soGiuong;
	NgayThang ngayNhapVien;
	int mucDo;
	Vaccine mui_1;
	Vaccine mui_2;
	Vaccine mui_3;
} BenhNhan;

// Ham kiem tra nam nhuan
bool laNamNhuan(int ngay);

// Ham tra ve so ngay cho truoc
int tinhSoNgayTrongThang(int thang, int nam);

// Ham kiem tra dd / mm / yyyy co hop le khong
bool laNgayHopLe(int ngay, int thang, int nam);

// Ham lay ra ngay
int getNgay(NgayThang date);
void setNgay(NgayThang &date);

// Ham lay ra thang
int getThang(NgayThang date);
void setThang(NgayThang &date);

// Ham lay ra nam
int getNam(NgayThang date);
void setNam(NgayThang &date);

// Ham lay ra ten vaccine
char *getTenVaccine(Vaccine *vx);
void setTenVaccine(Vaccine &vx);

// Ham lay ra ten benh nhap
char *getTenBenhNhan(BenhNhan *bn);
void setTenBenhNhan(BenhNhan &bn);

// Ham lay ra ten dan toc
char *getDanToc(BenhNhan *bn);
void setDanToc(BenhNhan &bn);

// Ham lay ra so dien thoai
char *getSDT(BenhNhan *bn);
void setSDT(BenhNhan &bn);

// Ham lay ra so CMND/CCCD
char *getCCCD_CMND(BenhNhan *bn);
void setCCCD_CMND(BenhNhan &bn);
 
// Ham lay ra nghe nghiep
char *getNgheNghiep(BenhNhan *bn);
void setNgheNghiep(BenhNhan &bn);

// Ham lay ra so bhyt
char *getBhyt(BenhNhan *bn);
void setBhyt(BenhNhan &bn);

// Ham lay ra noi thuong tru
char *getNoiThuongTru(BenhNhan *bn);
void setNoiThuongTru(BenhNhan &bn);


// Ham lay ra khoa dieu tri
char *getKhoaDieuTri(BenhNhan *bn);
void setKhoaDieuTri(BenhNhan &bn);

// Ham lay ra so giuong
int getSoGiuong(BenhNhan bn);
void setSoGiuong(BenhNhan &bn);

// Ham lay ra muc do nang nhe 
int getMucDo(BenhNhan bn);
void setMucDO(BenhNhan &bn);

// Ham nhap benh nhan
void nhapBenhNhap(BenhNhan &bn);

// Ham xuat benh nhan
void xuatBenhNhan(BenhNhan bn);

// Ham nhap danh sach benh nhan
void nhapDanhSachBenhNhan(BenhNhan *bn, int soLuong);

// Ham xuat danh sach benh nhan
void xuatDanhSachBenhNhan(BenhNhan *bn, int soLuong);

// Ham xuat thong tin vaccine
void xuatThongTinVaccine(BenhNhan bn);

// Ham xuat danh sach vaccine
void xuatDanhSachVaccine(BenhNhan *bn, int soLuong);

// Ham kiem so sanh 2 ngay
bool soSanhNgay(NgayThang ngay_1, NgayThang ngay_2);
	
// Ham them dau 
void themDau(BenhNhan *bn, int &soluong);

// Them cuoi
void themCuoi(BenhNhan *bn, int &soLuong);

// Them bat ky
void themBatKy(BenhNhan *bn, int &soLuong);

// Xoa dau
void xoaDau(BenhNhan *bn, int &soluong);

// Xoa cuoi
void xoaCuoi(BenhNhan *bn, int &soLuong);

// Xoa bat ky
void xoaBatKy(BenhNhan *bn, int &soLuong);

// Chuyen chu sang viet hoa
void vietHoachucai(char *x);

// Chuyen chu sang viet thuong
void vietThuongChuCai(char *x);

// Viet hoa chu cai dau 
void vietHoaChuCaiDau(BenhNhan *bn);

// Sap xep benh nhan theo ten abc
void sapXepBenhNhanTheoTen(BenhNhan *bn, int &soLuong);

// Ham tra ve so ngay chenh lech
int soNgayChenhLech(NgayThang ngay_1, NgayThang ngay_2);


	
	
