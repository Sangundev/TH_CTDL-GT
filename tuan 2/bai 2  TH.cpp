/// Nguyen Ngoc Sang
///201108714
///nguyenngocsang1682@gmail.

//// danh sach lien ket don ,voi info =  int  
#include<stdio.h>
#include<conio.h>
typedef struct CuonSach
{
	int masach;
	char tensach[40];
	float giasach;
}Sach;
typedef struct node
{ 
	Sach info; //// (data cung dc)
	node* pNext;	/// p=pointer
}Node;

typedef Node* NODEPTR;
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


void init(Node* &pHead)
{
	pHead = NULL;
}
////////////////========
void nhapsl(int &n)
{
	do{
		printf("\n\t nhap so luong so nguen <100 : ");
		scanf("%d",&n);
		if(n<1 )  printf("nhap lai :" );
	}while (n<1 );
}
///====================
Node* createNode(Sach x)
{

	Node* p = new Node;
	if( p!= NULL)
	{
		p->info = x,
		p->pNext = NULL;
	}
	return p;
}
//=================
void inserFirst(Node* &pHead,Sach x)
{
	Node* p = createNode(x);
	p->pNext = pHead;
	pHead = p;
}

//========================
void input(Node* &pHead)
{		
		int n; nhapsl(n);
		Sach x; 
		
		for(int i=0 ;i<n;i++)
		{
			printf(" nhap thong tin cuon sach thu %d: ",i+1);
			nhap1Sach(x);
			inserFirst(pHead, x);
		}
}

void output(Node* pHead)
{
	for(Node* i = pHead ; i!= NULL; i=i->pNext )
		xuat1Sach(i->info);
}
///==============================================
//int timtuyentinh(Node* pHead, int n, int key)
//{
//	Node* i = pHead;
//	while (i!= NULL && key != i->info)
//	   i=i->pNext;
//	   if(i!= NULL)  return Node* i;
//	   return -1;
//}
void swap(Sach &x, Sach &y)
{
	Sach tmp = x;
	x = y;
	y = tmp;
}
void sapxeptang(Node* &pHead){
	for (Node* i = pHead; i->pNext !=NULL ; i=i->pNext)///i<n-1 = i->pNext !=NULL 
		for(Node*j = i->pNext ; j != NULL ; j=j->pNext)
			if(i->info.masach > j->info.masach )
				swap(j->info,i->info);	
	}
//int timNhiPhan_tang(int a[], int n, int key)
//{
//	int left = 0, right = n-1, mid;
//	while(left <= right)
//	{
//		mid = (left+right)/2;
//		if(a[mid] == key)
//			return mid;
//		if(a[mid] < key)
//			left = mid+1;
//		else 
//			right = mid-1;
//	}
//	return -1;
//}
//=====================================================
//void menu(int &chon)
//{
//	printf("\n\n=======MENU==============\n");
//	printf("1- Linear Search\n");
//	printf("2- Binary Search\n");
//	printf("\n0- Exit\n");
//	printf("=========================\n");
//	printf("Ban chon chuc nang: ");
//	scanf("%d", &chon);
//}
void Auto_input(NODEPTR &pHead, Sach a[], int n)
{
	
		Sach x; 
		for(int i=0 ;i<n;i++){
			inserFirst(pHead , a[i]);
		}
}
//=====================================================
int main()
{
	NODEPTR pHead ;
		Sach a[10] =
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
	}; /// NODEPTR = node* pointet head
	int n = 10;
	
	init(pHead);
	
//	input(pHead);
	Auto_input(pHead, a, n);
	printf("\n noi dung moi nhap :\n");
	
	output(pHead);
	
	printf("\n tang dan ");
	sapxeptang(pHead);
	output(pHead);
	
	return 0;
} 