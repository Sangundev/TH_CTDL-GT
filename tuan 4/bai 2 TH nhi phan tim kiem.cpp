/// Nguyen Ngoc Sang
///201108714
///nguyenngocsang1682@gmail.com
//// cay nhi phan  (binary tree) //// tim kiem search BFT
#include<stdio.h>
#include<conio.h>

typedef struct node
{ 
	int info; //// (data cung dc)
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
Node* createNode(int x)
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
void insert(Node* &pRoot, int x )
{
	if(pRoot == NULL )     pRoot = createNode(x);
	else
	{
		if( x== pRoot->info ) return;
		if(x < pRoot->info)         insert(pRoot->pLeft,x);
		else /*x> pRoot->info*/     insert(pRoot->pRight,x);
	}
}
//////=======================================================================
void create_BTS(Node* &pRoot, int a[],int n)
{
	for(int i=0 ;i<n;i++)
	insert(pRoot,a[i]);
}
//////===============================================
///////////////////////////////////
//////////====================================
void NLR(Node * pRoot)
{
	if(pRoot != NULL)
	{
		printf("%4d",pRoot->info);
		NLR(pRoot->pLeft);
		NLR(pRoot->pRight);
	}
}

void LNR(Node * pRoot)
{
	if(pRoot != NULL)
	{
		LNR(pRoot->pLeft);
		printf("%4d",pRoot->info);
		LNR(pRoot->pRight);
	}
}

void LRN(Node * pRoot)
{
	if(pRoot != NULL)
	{
		LRN(pRoot->pLeft);
		LRN(pRoot->pRight);
		printf("%4d",pRoot->info);		
	}
}


///////////======================================
int main()
{
	int a[]= {5,3,8,6,2,9,1,4};
	int n = 8 ;
	
	Node* pRoot; /////////////////ptree
	init(pRoot);
	create_BTS(pRoot,a,n);
	
	printf("\nNLR :");               NLR(pRoot);
	printf("\nLRN :");             LNR(pRoot);
	printf("\nLRN :");             LRN(pRoot);
	
	printf("\n\n\n");
	
	
	
	return 0;
}