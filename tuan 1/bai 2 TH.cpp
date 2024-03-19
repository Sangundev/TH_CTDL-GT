// ==============================
// NGuyen Ngoc SANG
// MSSV: 2011068714
// ==============================
#include<stdio.h>
#include<conio.h>
#include <string.h>
#define MAX 100

//==========================================
typedef struct CuonSach
{
	int masach;
	char tensach[40];
	float giasach;
}Sach;
//==========================================
void nhap1Sach(Sach &x)
{
    printf("nhap ma cuon sach: ");
    scanf("%d",&x.masach);
    printf("nhap ten cuon sach: ");
    fflush(stdin);  gets(x.tensach);
    printf("nhap gia cuon sach: ");
    scanf("%f",&x.giasach);
}
//==========================================
void xuat1Sach(Sach x )
{
	printf("\n | %8d | %-40s | %.2f |", x.masach, x.tensach, x.giasach);
}
//=====================================================
void nhapSL(int &n) 
{
	do
	{	printf("\n\n\t Nhap so phan tu mang (0<N<=%d) : ", MAX);
		scanf("%d", &n);
		if(n<1 || n>MAX) printf("Ban nhap sai roi, (0<N<=%d) \n", MAX);
	}while(n<1 || n>MAX);	
}
//=====================================================
void nhapMang(Sach a[], int n)
{
	for(int i=0; i<n; i++)
	{
		printf("Nhap thong tin cuon sach thu %d : \n", i+1);
		nhap1Sach(a[i]);
	}
}
//=====================================================
void xuatMang(Sach a[], int n)
{
	for(int i=0; i<n; i++)
		xuat1Sach(a[i]);
}
//=====================================================
int timTuyenTinh(Sach a[],int n, int key)
{
	int i=0;
	while(i<n && key != a[i].masach)
		i++;
	if(i<n) return i;
	return -1;
}

//=====================================================
void swap(Sach &x, Sach &y)
{
	Sach temp = x;
	x = y;
	y = temp;
}
//=====================================================
void sapXepTang_MaSach(Sach a[], int n) // InterChangeSort_Inc
{
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(a[i].masach > a[j].masach)
				swap(a[i],a[j]);
}
//=====================================================
int timNhiPhan_Tang(Sach a[], int n, int key)
{
	int left = 0, right = n-1, mid;
	while(left <= right)
	{
		mid = (left+right)/2;
		if(a[mid].masach == key)
			return mid;
		if(a[mid].masach < key)
			left = mid+1;
		else 
			right = mid-1;
	}
	return -1;
}
void Max(Sach a[], int n)
{
	float max = a[0].giasach;
	for(int i = 0; i<n ; i++)
		if(a[i].giasach > max)
			max = a[i].giasach;
	for(int i=0 ; i<n; i++)
		if(a[i].giasach == max)
		xuat1Sach(a[i]);
}
void Min(Sach a[], int n)
{
	float min = a[0].giasach;
	for(int i = 0; i<n ; i++)
		if(a[i].giasach < min)
			min = a[i].giasach;
	for(int i=0 ; i<n; i++)
		if(a[i].giasach == min)
		xuat1Sach(a[i]);
}
void TimY(Sach a[], int n, char y[40])
{
	int dem=0;
	for(int i=0; i<n; i++)
	{
		if(strcmp(a[i].tensach,y)==0)
		{
			xuat1Sach(a[i]);
			dem++;
		}
	}
	if(dem==0)
		printf("Khong tim thay cuon sach nay.");
}
/////////////////////////////////////////////////////////
void xuat3s(Sach a[],int n)
{
	for(int i=0;i<3;i++)
	xuat1Sach(a[i]);
}
void sapXepgiam_giasach(Sach a[], int n) // InterChangeSort_Inc
{
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(a[i].giasach < a[j].giasach)
				swap(a[i],a[j]);
}
//=====================================================
void menu(int &chon)
{
	printf("\n\n=======MENU==============\n");
	printf("1- Linear Search\n");
	printf("2- Binary Search\n");
	printf("\n0- Exit\n");
	printf("=========================\n");
	printf("Ban chon chuc nang: ");
	scanf("%d", &chon);
}
//=====================================================
int main()
{
	Sach a[MAX] =
	{
		//int masach;	char tensach[40];	float giasach;
		{1004, "Lap trinh C", 		5.2},
		{1009, "Lap trinh Java", 	5.7},
		{1002, "Lap trinh Python", 	3.2},
		{1008, "Lap trinh Web", 	8.6},
		{1001, "Lap trinh Pascal", 	2.2},
		{1007, "Lap trinh C#", 		1.4},
		{1006, "Lap trinh mang", 	8.4},
		{1010, "Lap trinh AI", 		4.2},
		{1003, "Lap trinh Media", 	8.6},
		{1005, "Lap trinh Web", 	6.4}
	};
	int n = 10;
	int x = 1008, vt, chon;
	char y[40];
//	nhapSL(n);
//	nhapMang(a,n);
	printf("\n DANH SACH CAC CUON SACH : \n");
	xuatMang(a,n);

	sapXepTang_MaSach(a, n);
	printf("\n Noi dung mang sau khi sap tang: \n");
	xuatMang(a,n);
	printf("\n========= tim kiem tuyen tinh ========\n");			
				vt = timTuyenTinh(a, n, x);
				 
				if(vt != -1) 
				{
					printf("\n (X=%d) tai vi tri [%d]", x,vt );									
				}
				else 
				{
					printf("\n (X=%d) Khong ton tai", x);
				}
	printf("\n========= tim kiem nhi phan ========\n");
				sapXepTang_MaSach(a, n);
				printf("\n Noi dung mang sau khi sap tang: \n");
				xuatMang(a,n);
				
				vt = timNhiPhan_Tang(a, n, x);
				if(vt == -1) printf("\n (X=%d) Khong ton tai", x);
				else printf("\n (X=%d) tai vi tri [%d]", x, vt );
	printf("\n--------TIM SACH TEN Y------- ");
		printf("\nNhap ten sach can tim: ");
		fflush(stdin);								
		gets(y);
		TimY(a,n,y);
	printf("\nsach co gia cao nhat\n");
	Max(a,n);
	printf("\nsach co gia thap nhat\n");
	Min(a,n);
	printf("\n 3 quen sach co gia cao nhat --------\n");
	sapXepgiam_giasach(a, n);
	xuat3s(a,n);
	do
	{
		menu(chon);
		switch(chon)
		{
			case 1: //Linear Search / timTuyenTinh 
				
				vt = timTuyenTinh(a, n, x);
				if(vt != -1) 
				{
					printf("\n (X=%d) tai vi tri [%d]", x, vt );									
				}
				else 
				{
					printf("\n (X=%d) Khong ton tai", x);
				}
					
				break;
				
			case 2: // timNhiPhan_Tang
				sapXepTang_MaSach(a, n);
				printf("\n Noi dung mang sau khi sap tang: \n");
				xuatMang(a,n);
				
				vt = timNhiPhan_Tang(a, n, x);
				if(vt == -1) printf("\n (X=%d) Khong ton tai", x);
				else printf("\n (X=%d) tai vi tri [%d]", x, vt );				
				break;
			default: chon =0;
		}
		
	}while(chon != 0);
	
	return 0;	
}








