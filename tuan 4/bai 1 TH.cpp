/// Nguyen Ngoc Sang
///201108714
///nguyenngocsang1682@gmail.com
//// AP DUNG danh sach lien ket don ,voi info =  int  
///// STACK , DOI CO SO 
#include<stdio.h>
#include<conio.h>

typedef struct node
{ 
	int info; //// (data cung dc)
	node* pNext;	/// p=pointer
}Node;
typedef Node* NODEPTR;

typedef Node* STACK;
///==================================
void init(Node* &s)
{
	s = NULL;
}

////////////////========
void nhapn(int &n)
{
	do{
		printf("\n\t nhap n so ng duong DECIMAL <100 : ");
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
/////////////////////////------------------
void inserFirst(Node* &pHead,int x)//////////////////////doi ten push cung dc
{
	Node* p = createNode(x);
	p->pNext = pHead;
	pHead = p;
}
////////////////////////////////////===========================
Node* push(int x, STACK &s)////nhap dau 
{
	inserFirst(s,x);
}
/////////////======================
void deletefist( Node* &pHead){
	
	if(pHead == NULL)  return;
	
	Node* p = pHead;
	pHead = pHead->pNext; 
	delete (p);                   ////// luu y ch?y xong phai don dep bo nho
}
//=================
int pop(STACK &s, int &x) ////////////////trc khi xoa xuat ra xoa dau 
{
	if(s== NULL ) return 0;
	x = s->info;
	deletefist(s);
	return 1;
}
/////////===============================

void convert(int n, STACK &s , int coso)///////chuyen co so 
{
	
	while(n!= 0)
	{
		int sodu=n%coso;
		push(sodu,s); /////////////////////////////n%2 ,s
		n=n/coso;
	}
}
//////////================================
//void output(STACK &s)
//{
//	int x;
//	 while( s!= NULL )
//	 {
//	 	pop(s,x);
//	 	if(x>9)    printf("%c",'A'+x - 10);
//		 else printf("%4d",x);
//	 }	
//}


void output(STACK &s)
{
    while (s!= NULL)
    {
        int x;
        pop(s, x);
    //nếu x < 10 thi xuất bình thường
        if (x < 10)
        {
            printf("%d",x);
        }
    //nếu x >= 10 thì xuất chữ cái tương ứng
        else
        {
            if (x == 10)
            {
                printf("%c",'A');
            }
            else if (x == 11)
            {
                 printf("%c",'B');
            }
            else if (x == 12)
            {
                 printf("%c",'C');
            }
            else if (x == 13)
            {
                 printf("%c",'D');
            }
            else if (x == 14)
            {
                 printf("%c",'E');
             }
            else if (x == 15)
            {
                 printf("%c",'F');
            }
        }
    }
}
//=====================================================
//=====================================================
int main()
{
	 STACK s ; /// NODE* pHead;
	init(s);
	int n;
	nhapn(n);
		
	convert(n,s,16);       printf("\nHEX : ");  output(s);
	convert(n,s,8);        printf("\nOCT : ");  output(s);
	convert(n,s,2);        printf("\nBIN : ");  output(s);
	
	return 0;
} 