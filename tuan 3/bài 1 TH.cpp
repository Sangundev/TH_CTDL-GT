/// Nguyen Ngoc Sang
///201108714
///nguyenngocsang1682@gmail.com
//// danh sach lien ket don ,voi info =  int  
#include<stdio.h>
#include<conio.h>
#include<bits/stdc++.h>
#include <unistd.h>


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
/////////=====================================
void inserLast(Node* &pHead,int x){
	
	Node*p = createNode(x);
	if(pHead ==NULL)
	pHead = p ;
	else
	{
		//lap i->9( trc null)
		Node* i = pHead;
		while( i->pNext != NULL )
		 i=i->pNext	;
			
		i->pNext= p;	//ket noi p saou i
	}
}
/////======================================

void inserAfterP(Node* &p,int x)
{ 

  	if(p==NULL) return;

	Node* q = createNode(x);
	q->pNext = p->pNext ;
	p->pNext = q;
}

////========================================================
Node* lonnhat(Node* pHead)
{
	Node* max = pHead;
	for(Node* i = pHead->pNext; i!= NULL; i=i->pNext)
	{
		if(max->info < i->info) /////////////so sanh gia tri 
		{
			max = i;
		}
	}
	return max;

}
void chensaumax(Node* &pHead)
{

	 int x = 555;
	 Node* p = lonnhat(pHead);
	 inserAfterP(p,x);
 }
/////======================================
//////////========================

void nhanbanmax(Node* &pHead)
{
	 Node* p = lonnhat(pHead);
	 inserAfterP(p,p->info);
 }
///=======================
Node* nhonhat(Node* pHead)
{
	Node* min = pHead;
	for(Node* i = pHead->pNext; i!= NULL; i=i->pNext)
	{
		if(min->info > i->info) /////////////so sanh gia tri 
		{
			min = i;
		}
	}
	return min;

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
void inputlist_0stop(Node* &pHead)////////////////////napj vao toiws 0 laf duwngf
{
		int x, stt=1;
		
		do
		{
			printf(" nhap so nguyen thu %d: ",stt++);
			scanf("%d", &x );
			if(x!=0){
				inserLast(pHead, x);///////////////inserFirst(pHead, x);
			}
		}while(x!=0);
}
//////////================================
void output(Node* pHead)
{ 	if(pHead == NULL )    printf("\n danh sach rong ");
	for(Node* i = pHead ; i!= NULL; i=i->pNext )
			printf("%4d",i->info);
}
///==============================================
Node* timtuyentinh(Node* pHead, int n, int key)
{
	Node* i = pHead;
	while (i!= NULL && key != i->info)
	   i=i->pNext;
	   if(i!= NULL)  return i;
	   return NULL;
}
void swap(int &x, int &y)
{
	int tmp = x;
	x = y;
	y = tmp;
}
void sapxeptang(Node* &pHead){
	for (Node* i = pHead; i!= NULL; i=i->pNext)///i<n-1= i->pNext !=NULL 
		for(Node*j = i->pNext ; j != NULL ; j=j->pNext)
			if(i->info > j->info)
				swap(j->info,i->info);	
	}

int countnode(Node* pHead )
{
   	int count = 0;
	   if(pHead != NULL)
	   {
	   	for(Node*i = pHead ; i != NULL ; i=i->pNext)
					count ++;
		   } else {	
					printf(" danh sach rong ");	
  }
  		return count;
}
//=====================================================
void deletefist( Node* &pHead){
	
	if(pHead == NULL)  return;
	
	Node* p = pHead;
	pHead = pHead->pNext; 
	delete (p);                   ////// luu y ch?y xong phai don dep bo nho
}
//////=============================================
void deleteall(Node* &pHead)
{
	while(pHead != NULL	)
	deletefist(pHead);
}
///=====================================
void deleteLast(Node* &pHead)
{
	if(pHead == NULL || pHead->pNext == NULL ) //// dslk co 1 node
	deletefist(pHead);
	else{
//		for(Node* i = pHead; i->pNext->pNext != NULL; i=i->pNext)
		Node* i = pHead;
		while(i->pNext->pNext != NULL)
		i=i->pNext;
		Node *p = i->pNext;
		i->pNext = NULL;
		delete(p);
	}
}

///////////===========================================
void deleteafterp(Node* &p)
{
	if(p == NULL || p->pNext == NULL)      return;    
	
	Node* q = p->pNext;
	p->pNext = q->pNext;
	delete(q);

}
//////////////////==================================
void deletep(Node* &pHead,Node* &p)
{
	if(p == NULL)      return;    
	if(p==pHead)  deletefist(pHead);
 	else{
 		swap(p->info,p->pNext->info);
 		deleteafterp(p);
	 }
}
////////////////-===============================================
void xoamindau( Node* &pHead)
{
	Node* min = nhonhat(pHead);
	deletep(pHead,min);
}
////////////////========================================
Node* timtuyentinh(Node* pHead, int key)
{
	Node* i = pHead;
	while (i!= NULL && key != i->info)
	   i=i->pNext;
	   if(i!= NULL)  return i;
	   return NULL;
}
////////////////===============================
void deleteX(Node* pHead)
{
	Node *p=pHead;
	if(p==NULL || pHead->pNext == NULL){
		printf(" \nkhong tim thay nut xoa\n ");
	}else{
		p = pHead->pNext;
		pHead->pNext=p->pNext;
		delete p;
	}
}

//=====================================================
void menu(int &chon)
{
	printf("\n _______________________________________\n");
	printf("|                  \MENU/                 |\n");
	printf("|1-sap xep tang                          |\n");
	printf("|2-dem node                              |\n");
	printf("|3-max                                   |\n");
	printf("|4-min                                   |\n");
	printf("|5-chen sau 5555 sau MAX phat hien dau   |\n");
	printf("|6-them dau                              |\n");
	printf("|7-them cuoi                             |\n");
	printf("|8-nhan ban max                          |\n");
	printf("|9-xoa dau                               |\n");
	printf("|10-xoa cuoi                             |\n");
	printf("|11-xoa ngay sau min                     |\n");
	printf("|12-xoa tat ca                           |\n");
	printf("|13 xoa   tat ca    min                  |\n");
	printf("|14- xoa MIN dau                         |\n");
	printf("|15-nhap so nguyen x xoa node x          |\n");
	printf("|0-               Exit                   |\n");
	printf("|________________________________________|\n");
	printf("Ban chon chuc nang: ");
	scanf("%d", &chon);
	system("cls");
}
//=====================================================
int main()
{
	NODEPTR pHead ; /// NODEPTR = node* pointet head
	int chon,x=7,a;
	init(pHead);
	
	system("color 7C");
	inputlist_0stop(pHead);
	printf("\n noi dung moi nhap :\n");
	output(pHead); 
	
	
	Node* min = NULL	;
	Node* vt = NULL;
	do {
		menu(chon);
		switch(chon)
		{
			case 1: 
				printf("\n tang dan ");
				sapxeptang(pHead);
				output(pHead);
				break;
			case 2:
					printf("\n so node dang ton tai la %d ",countnode(pHead));
				break;
			case 3:
				printf(" \ngia tri lon nhat : %d\n",lonnhat(pHead)->info);
				break;
			case 4:
				printf(" \ngia tri lon nhat : %d\n",nhonhat(pHead)->info);
				break;
			case 5:
					printf("\n sau khi chen them sau max ");
					chensaumax(pHead);
					output(pHead);
				break;
			case 6:
				printf("them dau  \n");
				inserFirst(pHead,x);
				output(pHead);	
				break;
			case 7:
				printf("them cuoi \n");
				inserLast(pHead,x);
				output(pHead);
				
				break;
			case 8:
				printf("\n nhan ban max ");
				nhanbanmax(pHead);
				output(pHead);
				break;
			case 9:
				printf("xoa dau \n");
				deletefist(pHead);
				output(pHead);
				break;
			case 10:
				printf("xoa cuoi \n");
				deleteLast(pHead);
				output(pHead);
				break;
			case 11:
				 min = nhonhat(pHead);
				deleteafterp(min);
				printf("sao khi xoa sau min \n");
				output(pHead);
				break;
			case 12:
					printf("\n xoa tat ca \n");
					deleteall(pHead);
					output(pHead);
				break;
			case 13:
				
				break;
			case 14:
				xoamindau(pHead);
				printf("sao khi xoa sau min \n");
				output(pHead);
				break;
			case 15:
					printf("\nnhap so can xoa : ");
					scanf("%d",&x);
					 vt =timtuyentinh(pHead,x);
						if(vt == NULL )
						{
							printf(" phan tu (x=%d) khong co ton tai ",x);
						}
						else{
						    	deletep(pHead,vt);
						    	output(pHead);
						}
				break;
		default:
			break;
		}
	}while(chon != 0);
	return 0;
} 