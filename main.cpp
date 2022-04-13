#include "ThuVienCuaToi.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {	
	BenhNhan *DSBN;
	int soLuong;
	int luaChon;

	do {
		textcolor(15);
		printf("0. Thoat\n");
		printf("1. Nhap danh sach benh nhan\n");
		printf("2. Xuat danh sach benh nhan\n");
		printf("3. Xuat thong tin vaccine cua danh sach benh nhan\n");
		printf("4. Them vao dau\n");
		printf("5. Them vao cuoi\n");
		printf("6. Them vao bat ky\n");
		printf("7. Xoa benh nhan dau\n");
		printf("8. Xoa benh nhan cuoi\n");
		printf("9. Xoa benh nhan bat ky\n");
		printf("10. Xoa man hinh\n");
		printf("Nhap lua chon cua ban: ");
		scanf("%d", &luaChon);
		switch (luaChon) {
			case 0: {
				break;
			}
			case 1: {
				printf("Nhap so luong benh nhan: ");
				scanf("%d", &soLuong);
				DSBN = (BenhNhan *) malloc ((soLuong) * sizeof(BenhNhan));
				nhapDanhSachBenhNhan(DSBN, soLuong);
				break;
			}
			case 2: {
				xuatDanhSachBenhNhan(DSBN, soLuong);
				printf("\n");
				break;
			}
			case 3: {
				xuatDanhSachVaccine(DSBN, soLuong);
				printf("\n");
				break;
			}
			case 4:{
			DSBN = (BenhNhan*) realloc(DSBN, (soLuong+1) * sizeof(BenhNhan));
				themDau(DSBN, soLuong);
				break;
			}
			case 5:{
				DSBN = (BenhNhan*) realloc (DSBN, (soLuong+1) * sizeof(BenhNhan));
				themCuoi(DSBN, soLuong);
				break;
			}
			case 6:{
				DSBN = (BenhNhan*) realloc(DSBN, (soLuong+1) * sizeof(BenhNhan));
				themBatKy(DSBN, soLuong);
				break;
			}
			case 7:{
				xoaDau(DSBN, soLuong);
				DSBN = (BenhNhan *) realloc (DSBN, (soLuong) * sizeof(BenhNhan));
				break;
			}
			case 8: {
				xoaCuoi(DSBN, soLuong);
				DSBN = (BenhNhan *) realloc (DSBN, (soLuong) * sizeof(BenhNhan));
				break;
			}
			case 9: {
				xoaBatKy(DSBN, soLuong);
				DSBN = (BenhNhan *) realloc (DSBN, (soLuong) * sizeof(BenhNhan));
				break;
			}
			case 10:{
				sapXepBenhNhanTheoTen(DSBN,soLuong);
				break;
			}
		}
	} while (luaChon != 0);
	free(DSBN);
	return 0;
}
