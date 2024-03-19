/// Nguyen Ngoc Sang
///201108714
///nguyenngocsang1682@gmail.com
//// cay nhi phan  (binary tree) 
#include<stdio.h>
#include<conio.h>

typedef struct node
{ 
	int info; //// (data cung dc)
	node* pLeft;
	node* pRight;	/// p=pointer
}Node;
typedef Node* NODEPTR;

typedef Node* STACK;
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
//////=======================================================================
void createBinaryTree(Node* &pRoot, int a[], int begin, int end)
{
	if (begin > end) return;
	int i = (begin+end)/2;
	pRoot = createNode(a[i]);
	createBinaryTree(pRoot->pLeft,  a, begin, i-1);
	createBinaryTree(pRoot->pRight, a, i+1,   end);
}
//////===============================================
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
	int begin = 0 , end = n-1;
	
	Node* pRoot; /////////////////ptree
	 init(pRoot);
	createBinaryTree(pRoot,a,begin,end);
	
	printf("NLR :");               NLR(pRoot);
	printf("\nLRN :");             LNR(pRoot);
	printf("\nLRN :");             LRN(pRoot);
	
	printf("\n\n\n");
	
	
	
	return 0;
}