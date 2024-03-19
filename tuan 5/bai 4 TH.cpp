#include <bits/stdc++.h>
#include <unistd.h>
typedef struct Node {
	int info;
	Node *Left;
	Node *Right;
	int height;
} Node;

void Init(Node *&root) {
	root = NULL;
}
Node *createNode(int x) {
	Node *p = new Node;
	if (p == NULL)
		return NULL;

	p->info = x;
	p->Left = NULL;
	p->Right = NULL;
	p->height = 1;
	return p;
}

bool isEmpty(Node *root) {
	if (root == NULL) {
		return true;
	}
	return false;
}
int getHight(Node *root) {
	if (isEmpty(root) == true)
		return 0;
	return root->height;
}

int balanceFactor(Node *&root) {
	if (isEmpty(root) == true)
		return 0;
	return getHight(root->Left) - getHight(root->Right);
}
int getMax(int a, int b) {
	return a > b ? a : b;
}
Node *rotateLeft(Node *&root) {
	if (isEmpty(root) == true)
		return NULL;
	if (root->Right == NULL)
		return NULL;

	Node *pivot = root->Right;
	root->Right = pivot->Left;
	pivot->Left = root;
	root->height = 1 + getMax(getHight(root->Right), getHight(root->Left));
	pivot->height = 1 + getMax(getHight(pivot->Right), getHight(pivot->Left));
	return pivot;
}

Node *rotateRight(Node *&root) {
	if (isEmpty(root) == true)
		return NULL;
	if (root->Left == NULL)
		return NULL;

	Node *pivot = root->Left;
	root->Left = pivot->Right;
	pivot->Right = root;
	root->height = 1 + getMax(getHight(root->Right), getHight(root->Left));
	pivot->height = 1 + getMax(getHight(pivot->Right), getHight(pivot->Left));
	return pivot;
}

Node *balance(Node *&root) {
	if (balanceFactor(root) < -1) {
		if (balanceFactor(root->Right) > 0) {
			root->Right = rotateRight(root->Right);
		}
		root = rotateLeft(root);
	} else if (balanceFactor(root) > 1) {
		if (balanceFactor(root->Left) < 0) {
			root->Left = rotateLeft(root->Left);
		}
		root = rotateRight(root);
	}
	return root;
}

Node *Insert(Node *&root, int x) {
	if (isEmpty(root) == true) {
		Node *p = createNode(x);
		root = p;
	} else {
		if (x < root->info) {
			root->Left = Insert(root->Left, x);
		} else if (x > root->info) {
			root->Right = Insert(root->Right, x);
		}
	}
	root->height = 1 + getMax(getHight(root->Left), getHight(root->Right));
	return balance(root);
}
///==================
void nhapsl(int &n) {
	do {
		printf("\n\t nhap so luong so nguen <100 : ");
		scanf("%d",&n);
		if(n<1 )  printf("nhap lai :" );
	} while (n<1 );
}
void input(Node* &pHead) {
	int n;
	nhapsl(n);
	int x;

	for(int i=0 ; i<n; i++) {
		printf(" nhap so nguyen thu %d: ",i+1);
		scanf("%d", &x );
		Insert(pHead, x);
	}
}
///==========================================================
void create_BTS(Node* &pRoot, int a[],int n) {
	for(int i=0 ; i<n; i++)
		Insert(pRoot,a[i]);
}
int chieucao(Node* pRoot) {
	if(pRoot == NULL )
		return 0;

	int a = chieucao(pRoot->Left);
	int b = chieucao(pRoot->Right);
	if(a > b)
		return 1 + a;
	return 1 + b;
}
void Nodek(Node*pRoot, int k) {
	if(pRoot != NULL) {
		k--;
		Nodek(pRoot->Left,k);
		if(k==0)   printf("%6d",pRoot->info);
		Nodek(pRoot->Right,k);
	}
}
Node * minValueNode(Node* p) {
	Node* current = p;
	while (current && current->Left != NULL)
		current = current->Left;
	return current;
}
Node * removeNode(Node *&root, int x) {
	if (root == NULL)
		return root;
	if (root->info > x)
		root->Left = removeNode(root->Left, x);
	else if (root->info < x)
		root->Right = removeNode(root->Right, x);
	else {

		if (root->Left == NULL) {
			Node *temp = root->Right;
			delete root;
			return temp;
		} else if (root->Right == NULL) {
			Node *temp = root->Left;
			delete root;
			return temp;
		}
		Node *temp = minValueNode(root->Right);
		root->info = temp->info;
		root->Right = removeNode(root->Right, temp->info);
	}
	if (root == NULL)
		return root;
	root->height = 1 + getMax(getHight(root->Left), getHight(root->Right));
	return balance(root);
}
void menu() {
	Node *root;
	//int n;
	Init(root);
	int a[]= {18, 24, 14, 28, 16, 20, 10, 22, 12, 26};
	int n = 10;
	int c;
	int i;
	int x;
//	create_BTS(root,a,n);
	do {
		input(root);
//		create_BTS(root,a,n);
		c = chieucao(root);
		printf("\nchieu cao cua cay la : %d",c);
		for(i =1 ; i<= c ; i++) {
			printf("\nLEVER %d :",i);
			Nodek(root,i);
		}
		printf("\nNhap node:");
		scanf("%d", &x);
		removeNode(root,x);
		printf("\n");
		for(i =1 ; i<= c ; i++) {
			printf("\nLEVER %d :",i);
			Nodek(root,i);
		}
	} while(x!=0);
}
int main() {
	menu();
	return 0;
}
