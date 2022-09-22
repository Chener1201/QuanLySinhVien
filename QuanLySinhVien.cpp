#include <stdio.h>
#include <iostream>

typedef struct			// khai báo struct sinh viên
{
	int MSSV;			// mã số
	char HoTen[40];		// họ tên
	char Lop[5];		// lớp
	float LTC;			// điểm Lập trình C
	float DTCB;			// điểm Điện tử cơ bản
	float NMKT;			// điểm Nhập môn kỹ thuật
	float DTB;			// điểm trung bình = trung bình 3 môn
} SinhVien;


void Nhap1SV(SinhVien &sv)						// hàm nhập 1 sinh viên
{
	printf("Nhap MSSV:");scanf("%d",&sv.MSSV);
	fflush(stdin);								// xóa bộ nhớ đệm
	printf("Nhap Ho Ten:");gets(sv.HoTen);
	fflush(stdin);								// xóa bộ nhớ đệm
	printf("Nhap Lop:");gets(sv.Lop);
	printf("Nhap diem Lap Trinh C:");scanf("%f",&sv.LTC);
	printf("Nhap diem Dien Tu Co Ban:");scanf("%f",&sv.DTCB);
	printf("Nhap diem Nhap mon ky thuat:");scanf("%f",&sv.NMKT);
	sv.DTB  = (sv.LTC +  sv.DTCB + sv.NMKT)/3.0;   // điểm trung bình được tính
}

void NhapSV(SinhVien sv[], int &N)				// hàm nhập N sinh viên
{
	printf("Nhap so sinh vien:"); scanf("%d", &N);
	for(int i=0;i<N;i++) 
	{
		printf ("\nSinh vien thu %d\n",i+1);
		Nhap1SV(sv[i]);
	}
}

void In1SV(SinhVien sv)							// hàm in 1 sinh viên
{
	printf("\n%d",sv.MSSV);
	printf("\t%s",sv.HoTen);
	printf("\t%s",sv.Lop);
	printf("\t%0.2f",sv.LTC);
	printf("\t%5.2f",sv.DTCB);
	printf("\t%5.2f",sv.NMKT);
	printf("\t\t%5.2f",sv.DTB);
}

void InSV(SinhVien sv[], int N)					// hàm in N sinh viên
{
	printf ("\nDanh sach sinh vien:\n");
	printf("\nMSSV\tHo ten\tLop\tLT C\tDTCB\tNhap mon KT\tDiem TB\n");
	for(int i=0;i<N;i++) 
	{
		In1SV(sv[i]);
	}
}

void ChinhSV(SinhVien sv[])						// hàm chỉnh sửa thông tin 1 sinh viên
{
	int i;
	printf ("\nChinh sua thong tin sinh vien:\n");
	printf ("Nhap vi tri sinh vien can chinh:");
	scanf ("%d",&i); i--;
	printf ("\nThong tin cu:\n"); In1SV(sv[i]);
	printf ("\nThong tin chinh sua:\n"); Nhap1SV(sv[i]);
}

void LietKeSVlon5(SinhVien sv[], int N)			// hàm liệt kê sinh viên có điểm trung bình lớn hơn hoặc bằng 5
{
	int i;
	printf ("\nThong tin sinh vien co diem trung binh lon hon hoac bang 5.0:\n");
	printf("\nMSSV\tHo ten\tLop\tLT C\tDTCB\tNhap mon KT\tDiem TB\n");
	for(int i=0;i<N;i++) 
	{
		if (sv[i].DTB>=5) In1SV(sv[i]);			// nếu sinh viên nào có ĐTB >= 5 thì in ra
	}
}

void DTB_CaoNhat(SinhVien sv[], int N)			// tìm sinh viên có ĐTB cao nhất
{
	int i;
	SinhVien temp;								// biến tạm SinhVien
	printf ("\nThong tin sinh vien co diem trung binh cao nhat:\n");
	printf("\nMSSV\tHo ten\tLop\tLT C\tDTCB\tNhap mon KT\tDiem TB\n");
	temp = sv[0];								// biến tạm bằng sinh viên đầu tiên
	for(int i=1;i<N;i++) 
	{
		if (sv[i].DTB>temp.DTB) temp = sv[i];	// nếu sinh viên i có ĐTB cao hơn biến tạm thì biến tạm bằng sinh viên i
	}	
	In1SV(temp);
}

void XepDanhSach(SinhVien sv[], int N)			// xếp lại danh sách sinh viên theo ĐTB từ cao xuống thấp
{
	int i,j;
	SinhVien temp;
	for(int i=0;i<N-1;i++)
		for(int j=i+1;j<N;j++)
			if (sv[i].DTB<sv[j].DTB)			// nếu sinh viên i có ĐTB nhỏ hơn sinh viên j thì
			{									// hoán đổi vị trí giữa 2 sinh viên i và j
				temp = sv[i] ;
				sv[i] = sv[j];
				sv[j] = temp;
			}
	InSV(sv, N);
}

int main()
{
	SinhVien sv[20];							// struct sinh viên tối đa 20 người
	int N=0;									// N là tổng số sinh viên
	char kt;

	do
	{	printf ("\n\nChon 1 trong cac lua chon sau:\n");
		printf ("1. Nhap danh sach sinh vien\n");
		printf ("2. In danh sach sinh vien\n");
		printf ("3. Chinh sua thong tin 1 sinh vien\n");
		printf ("4. Liet ke sinh vien co diem trung binh lon hon hoac bang 5.0\n");
		printf ("5. Tim sinh vien co diem trung binh cao nhat\n");
		printf ("6. Xep danh sach theo diem trung binh tu cao xuong thap\n");
		printf ("Bam q hoac Q de thoat:\n");
		scanf("%c",&kt) ;
		
		switch(kt)
		{
			case '1': NhapSV(sv, N); break;
			case '2': InSV(sv, N); break;
			case '3': ChinhSV(sv); break;
			case '4': LietKeSVlon5(sv, N); break;
			case '5': DTB_CaoNhat(sv,N); break;
			case '6': XepDanhSach(sv,N); break;
			case 'q':
			case 'Q':
				break;	
			// case '7': LuuSV_FileNhiPhan(sv,N); break;
			// case '8': DocSV_FileNhiPhan(sv,N); break;
			default: printf("Nhap so sai!!! Hay nhap lai");
		}
		
	}  while(!(kt=='q' || kt=='Q'));
	return 0;
}