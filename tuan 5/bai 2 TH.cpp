/// Nguyen Ngoc Sang
///201108714
///nguyenngocsang1682@gmail.com
//// cay nhi phan  (binary tree) //// tim kiem search Bst so nguyen
#include<stdio.h>
#include<conio.h>
#include<bits/stdc++.h>
#include <unistd.h>

typedef struct CuonSach
{
	int masach;
	char tensach[40];
	float giasach;
}Sach;
//==============================
void nhap1Sach(Sach &x)
{
    printf("nhap ma cuon sach: ");
    scanf("%d",&x.masach);
    printf("nhap ten cuon sach: ");
    fflush(stdin);  gets(x.tensach);
    printf("nhap gia cuon sach: ");
    scanf("%f",&x.giasach);
}
//==============================
void xuat1Sach(Sach x )
{
      printf("\n|%8d|%-40s|%8.2f|", 
       x.masach,  x.tensach,    x.giasach);
}

typedef struct node
{ 
	Sach info; //// (data cung dc)
	node* pLeft;
	node* pRight;	/// p=pointer
}Node;
typedef Node* NODEPTR;

///===============================================================================
void init(Node* &pRoot)
{
	pRoot = NULL;
}
///=============================================================================
Node* createNode(Sach x)
{

	Node* p = new Node;
	if(p!= NULL)
	{
		p->info = x,
		p->pLeft = NULL;
		p->pRight = NULL;
	}
	return p;
}
////////////=====================================
void insert(Node* &pRoot, Sach x )
{
	if(pRoot == NULL )     pRoot = createNode(x);
	else
	{
		if( x.masach== pRoot->info.masach ) return;
		if(x.masach < pRoot->info.masach)         insert(pRoot->pLeft,x);
		else /*x> pRoot->info*/     insert(pRoot->pRight,x);
	}
}
//////=======================================================================
void create_BTS(Node* &pRoot, Sach a[],int n)
{
	for(int i=0 ;i<n;i++)
	insert(pRoot,a[i]);
}
//////===============================================
//////////====================================
void NLR(Node * pRoot)
{
	if(pRoot != NULL)
	{
		xuat1Sach(pRoot->info);
		NLR(pRoot->pLeft);
		NLR(pRoot->pRight);
	}
}

void LNR(Node * pRoot)
{
	if(pRoot != NULL)
	{
		LNR(pRoot->pLeft);
//		printf("%4c",pRoot->info);
		xuat1Sach(pRoot->info);
		LNR(pRoot->pRight);
	}
}

void LRN(Node * pRoot)
{
	if(pRoot != NULL)
	{
		LRN(pRoot->pLeft);
		LRN(pRoot->pRight);
		xuat1Sach(pRoot->info);		
	}
}

///====================================================
void menu(int &chon);
////====================================================

///////////======================================
int demNode(Node* pRoot){
	if(pRoot == NULL )    return 0;
//	else
//	{//////1 ban than nos prot khac null 
		return 1 + demNode(pRoot->pLeft) + 
					demNode(pRoot->pRight);
//		}
}
/////////////=================================================
int demla(Node* pRoot){
	if(pRoot == NULL ) return 0;
	if(pRoot->pLeft == NULL && pRoot->pRight == NULL) return 1;
	return demla(pRoot->pLeft) + demla(pRoot->pRight);
}
////=====================================================
void xuatla(Node *pRoot){
	if(pRoot != NULL )  {
	 	if(pRoot->pLeft == NULL && pRoot->pRight == NULL) 
//		     printf("%c\t",pRoot->info);  
			xuat1Sach(pRoot->info);
		 xuatla(pRoot->pLeft) ; 
		 xuatla(pRoot->pRight);
	}
}
////====================================
int demNode2Con(Node* pRoot)
{
	if (pRoot==NULL) return 0;
	int dem = 0;
	if (pRoot->pLeft!=NULL && pRoot->pRight!=NULL) dem = 1;
	return	dem + 	demNode2Con(pRoot->pLeft) + 
			demNode2Con(pRoot->pRight);
}
void xuat2conla(Node *pRoot){
	if(pRoot != NULL )  {
	 	if(pRoot->pLeft == NULL && pRoot->pRight == NULL) 
		     xuat1Sach(pRoot->info);  
		 xuat2conla(pRoot->pLeft) ; 
		 xuat2conla(pRoot->pRight);
	}
}
/////////==================================================================
int demNode1Con(Node* pRoot)
{
	if (pRoot==NULL) return 0;
	int dem = 0;
	if ((pRoot->pLeft!=NULL && pRoot->pRight==NULL)||
	(pRoot->pLeft==NULL && pRoot->pRight!=NULL))
	dem = 1;
	return	dem + demNode1Con(pRoot->pLeft) + 
			demNode1Con(pRoot->pRight);
}
void xuat1conla(Node *pRoot){
	if(pRoot != NULL )  {
	 	if((pRoot->pLeft != NULL && pRoot->pRight == NULL)||
	 	(pRoot->pLeft!=NULL && pRoot->pRight==NULL))
		     xuat1Sach(pRoot->info);  
		 xuat1conla(pRoot->pLeft) ; 
		 xuat1conla(pRoot->pRight);
	}
}
/////////===========================================================
//int sum(Node *pRoot){
//	if(pRoot == NULL)   return 0;
//	int a = sum(pRoot->pLeft);
//	int b = sum(pRoot->pRight);
//	return a+b + pRoot->info ;
//}
//=======================================================

//int max;
//Node* Max(Node* pRoot) {
//	if(pRoot != NULL) {
//		if(max < pRoot->info) {
//			max = pRoot->info;
//		}
//		Max(pRoot->pRight);
//	}
//}
////=======================================================

//int min;
//Node* Min(Node* pRoot) {
//	if(pRoot != NULL) {
//		if(min > pRoot->info) {
//			min = pRoot->info;
//		}
//		Min(pRoot->pLeft);
//	}
//}

/////////======================================================================

//============================================================
int chieucao(Node* pRoot){
   if(pRoot == NULL )
       return 0;

    int a = chieucao(pRoot->pLeft);
    int b = chieucao(pRoot->pRight);
    if(a > b)
        return 1 + a;
    return 1 + b;
}
///////================================================
void Nodek(Node*pRoot, int k)
{
	if(pRoot != NULL)
	{
		k--;
		Nodek(pRoot->pLeft,k);
		if(k==0)   printf("%6c",pRoot->info);
		Nodek(pRoot->pRight,k);
	}	
}
/////=========================================================================
////=================================================================
//Node* search(Node* pRoot, Sach x) {
//	if (pRoot == NULL) {
//		return NULL;
//	} else {
//		if(pRoot->info.masach > x.masach) {
//			search(pRoot->pLeft, x.masach);
//		} else if(pRoot->info.masach < x.masach) {
//			search(pRoot->pRight, x);
//		} else {
//			return pRoot;
//		}
//	}
//}
//=================
//void searchTree(Node* pRoot) {
//	int x;
//	printf("- Nhap Gia Tri Can Tim Kiem: ");
//	scanf("%d", &x);
//	Node* p = search(pRoot, x);
//	if(p == NULL) {
//		printf("\n- %d Khong Ton Tai Trong Cay", x);
//	} else {
//		printf("\n- %d Co Ton Tai Trong Cay", x);
//	}
//}
///=======================================================
int main()
{
	system("color 7C");
//	int a[]= {5,3,8,6,2,9,1,4,3,3,2,9};
//	int n = 12,c,i ;
	char a[]= {'G','U','W','B','Q','A','O','X'};
	int n = 8 ;

//	Sach a[10] ={
//	{1004, "Lap trinh C", 	5.2},
//	{1009, "Lap trinh Java", 	5.7},
//	{1002, "Lap trinh Python",3.2},
//	{1008, "Lap trinh Web", 	8.6},
//	{1001, "Lap trinh Pascal", 2.2},
//	{1007, "Lap trinh C#", 	1.4},
//	{1006, "Lap trinh mang", 	8.4},
//	{1010, "Lap trinh AI", 	4.2},
//	{1003, "Lap trinh Media", 8.6},
//	{1005, "Lap trinh Phone"	,6.4}
//};
//int n = 10;
	int chon,c,i;
	Node* pRoot; /////////////////ptree
	init(pRoot);
	create_BTS(pRoot,a,n);
	
	int x;
	system("cls");
	do{
		menu(chon);
		system("cls");
		switch(chon)
		{
		case 1:// Duyet cay theo NLR - LNR - LRN
				printf("\nNLR :");               NLR(pRoot);
				printf("\nLNR :");             LNR(pRoot);
				printf("\nLRN :");             LRN(pRoot);
			break;
		case 2:// Dem so Node cua BST
			printf(" so luong NODE cuar BST :%d ",	demNode(pRoot));
			break;
		case 3://Dem so Node LA cua BS
			printf(" so luong NODE la BST :%d\n ", demla(pRoot));
			printf(" NODE cua la  BST\n ");
			xuatla(pRoot);
			break;
		case 4://Dem so Node 2 con cua BST
				printf("dem NODE 2 con cua BST%d\n ",demNode2Con(pRoot));
				printf(" NODE cua la  BST\n ");
				xuat2conla(pRoot);
			break;
		case 5://Dem so Node 1 con cua BST
				printf("dem NODE 1 con cua BST%d\n ",demNode1Con(pRoot));
				printf(" \nNODE cua la  BST\n ");
				xuat1conla(pRoot);
			break;
		case 6://Tong Info cua BST
			printf(" tong NODE la BST :%d\n ", sum(pRoot));
			break;
		case 7://Info Max cua BST
				create_BTS(pRoot,a,n);
				Max(pRoot);
				printf(" NODE lon la BST :%d\n ", max);
			break;
		case 8://Info Min cua BST
				create_BTS(pRoot,a,n);
				Min(pRoot);
				printf(" NODE be la BST :%d\n ", min);
			break;
		case 9://Chieu cao cua BST
				create_BTS(pRoot,a,n);
				c = chieucao(pRoot);
				printf("chieu cao cua cay la : %d",c);
				for(i =1 ; i<= c ;i++){
					printf("\nLEVER %d :",i);
					Nodek(pRoot,i);
				}
			break;
		case 10://Xuat cac Node tren BAC K cua BST
			break;
		case 11://Xoa tat ca Node cua BST
			break;
		case 12:// Xoa Node X cua BST
//			printf(" \n nhap phan tu can xoa : ");
//			scanf("%d",&x);
//			XoaNode(pRoot,x);
			break;
		case 13:// Tim kiem tren BST
			searchTree(pRoot);
			break;
		}
	}while(chon);
	
	
	return 0;
}
void menu(int &chon)
{
	printf("\n\n ================= BST <int> ======================");
	printf("\n  1: Duyet cay theo NLR - LNR - LRN");
    printf("\n  2: Dem so Node cua BST");
    printf("\n  3: Dem so Node LA cua BST");
    printf("\n  4: Dem so Node 2 con cua BST");
    printf("\n  5: Dem so Node 1 con cua BST");
    printf("\n  6: Tong Info cua BST");
    printf("\n  7: Info Max cua BST");
    printf("\n  8: Info Min cua BST");
    printf("\n  9: Chieu cao cua BST");
    printf("\n 10: Xuat cac Node tren BAC K cua BST");
    printf("\n 11: Xoa tat ca Node cua BST");
	printf("\n 12: Xoa Node X cua BST");
    
    printf("\n 13: Tim kiem tren BST");
    
    printf("\n\n 0: Thoat");
    printf("\n ====================================================");
    printf("\n Vui long chon cong viec: ");
    scanf("%d", &chon);
}
