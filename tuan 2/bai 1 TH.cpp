/// Nguyen Ngoc Sang
///201108714
///nguyenngocsang1682@gmail.com
//// danh sach lien ket don ,voi info =  int  
#include<stdio.h>
#include<conio.h>

typedef struct node
{ 
	int info; //// (data cung dc)
	node* pNext;	/// p=pointer
}Node;

typedef Node* NODEPTR;


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
Node* createNode(int x)
{

	Node* p = new Node;
	if(p!= NULL)
	{
		p->info = x,
		p->pNext = NULL;
	}
	return p;
}
//=================
void inserFirst(Node* &pHead,int x)
{
	Node* p = createNode(x);
	p->pNext = pHead;
	pHead = p;
}

//========================
void input(Node* &pHead)
{		
		int n; nhapsl(n);
		int x; 
		
		for(int i=0 ;i<n;i++)
		{
			printf(" nhap so nguyen thu %d: ",i+1);
			scanf("%d", &x );
			inserFirst(pHead, x);
		}
}
////==================
//////////================================
void output(Node* pHead)
{
	for(Node* i = pHead ; i!= NULL; i=i->pNext )
			printf("%4d",i->info);
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
void swap(int &x, int &y)
{
	int tmp = x;
	x = y;
	y = tmp;
}
void sapxeptang(Node* &pHead){
	for (Node* i = pHead; i!= NULL; i=i->pNext)///i<n-1 = i->pNext !=NULL 
		for(Node*j = i->pNext ; j != NULL ; j=j->pNext)
			if(i->info > j->info)
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
	NODEPTR pHead ; /// NODEPTR = node* pointet head
	
	
	init(pHead);
	
	input(pHead);

	printf("\n noi dung moi nhap :\n");
	
	output(pHead);
	
	printf("\n tang dan ");
	sapxeptang(pHead);
	output(pHead);
	
	return 0;
} 