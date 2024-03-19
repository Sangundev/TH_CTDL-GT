/// Nguyen Ngoc Sang
///201108714
///nguyenngocsang1682@gmail.com
#include<stdio.h>
#include<conio.h>
#define MAX 100
void nhapsl(int &n)
{
	do{
		printf("\n\t nhap so phan tu cua mang <100 : ", MAX);
		scanf("%d",&n);
		if(n<1 || n>MAX )  printf("nhap lai :",MAX );
	}while (n<1 || n>MAX );
}
void nhap(int a[], int n)
{
		for(int i=0 ;i<n;i++)
		{
			printf(" nhap a[%d]: ",i);
			scanf("%d", &a[i] );
		}
}

void xuat(int a[], int n)
{

		for(int i=0 ;i<n;i++)
		{
			printf("%4d",a[i]);
		}

}
int timtuyentinh(int a[], int n, int key)
{
	int i=0;
	while (i<n && key != a[i])
	   i++;
	   if(i<n)  return i;
	   return -1;
}
void swap(int &x, int &y)
{
	int tmp = x;
	x = y;
	y = tmp;
}
void sapxeptang(int a[], int n){
	for (int i = 0; i<n-1;i++)
		for(int j=i+1 ; j<n ; j++)
			if(a[i] > a[j])
		swap(a[i],a[j]);	
	}
int timNhiPhan_tang(int a[], int n, int key)
{
	int left = 0, right = n-1, mid;
	while(left <= right)
	{
		mid = (left+right)/2;
		if(a[mid] == key)
			return mid;
		if(a[mid] < key)
			left = mid+1;
		else 
			right = mid-1;
	}
	return -1;
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
	int a[MAX] = {6,5,8,-7,1,0,-9,4};
	int n = 8;
	int x = -7, vt ,chon;
	//nhapsl(n);
	//nhap(a,n);
	printf("\n ----------tim kiem tuyen tinh --------------");
	printf("\n phan tu vua moi nhap la \n");
	xuat(a,n);
	 vt = timtuyentinh(a,n,x);
	if(vt == -1 ) printf("\n (x=%d) khong ton tai ", x);
	else printf("\n (x=%d) tai vi tri [%d]",x,vt);
	printf("\n-------------tim kiem nhi phan ----------------\n");
	sapxeptang(a,n);
	printf("\n noi dung mang khi tang la : \n ");
	xuat(a,n);
	vt = timNhiPhan_tang(a,n,x);
	if(vt == -1 ) printf("\n (x=%d) khong ton tai ", x);
	else printf("\n (x=%d) tai vi tri [%d]",x,vt );
	
	do
	{
		menu(chon);
		switch(chon)
		{
			case 1: //Linear Search / timTuyenTinh 
					printf("\n phan tu vua moi nhap la \n");
					xuat(a,n);
					 vt = timtuyentinh(a,n,x);
					if(vt == -1 ) printf("\n (x=%d) khong ton tai ", x);
							
				break;
				
			case 2: // timNhiPhan_Tang
					sapxeptang(a,n);
					printf("\n noi dung mang khi tang la : \n ");
					xuat(a,n);
					vt = timNhiPhan_tang(a,n,x);
					if(vt == -1 ) printf("\n (x=%d) khong ton tai ", x);
					else printf("\n (x=%d) tai vi tri [%d]",x,vt );		
				break;
			default: chon =0;
		}
	}while(chon != 0);
	return 0;
} 