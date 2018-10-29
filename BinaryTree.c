#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// int 타입을 가지는 BTData 타입을 선언 
typedef int BTData;

// 이진트리의 노드를 구조체로 선언. 
//data/ left link (포인터) / right link (포인터)  
typedef struct _bTreeNode{
	BTData data;
	struct _bTreeNode * left;
	struct _bTreeNode * right;
}BTreeNode;

//전위 순회
void PreorderTraverse(BTreeNode * bt){
	if(bt == NULL) return;
	PreorderTraverse(bt->data);
	printf("%d \n",bt->left);
	PreorderTraverse(bt->right);

} 

//중위순회 
void InorderTraverse(BTreeNode * bt){
	if(bt == NULL) return;
	InorderTraverse(bt->left);
	printf("%d \n",bt->data);
	InorderTraverse(bt->right);

}

BTreeNode * MakeExpTree(char exp[]);
int EvaluateExpTree(BTreeNode * bt);

void ShowPrefixTypeExp(BTreeNode *bt);
void ShowInfixTypeExp(BTreeNode *bt);
void ShowPostfixTypeExp(BTreeNode *bt);


BTreeNode * MakeBTreeNode(void){
	BTreeNode *nd = (BTreeNode*)malloc(sizeof(BTreeNode));
	
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

BTData GetData(BTreeNode *bt){
	return bt->data;
}

void SetData (BTreeNode * bt, BTData data){
	bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt){
	return bt->left;
}

BTreeNode * GetRightSubTree(BTreeNode * bt){
	return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode *sub){
	if (main->left != NULL)
		free(main->left);
		
	main->left = sub;
}

void MakeRightSubTree(BTreeNode * main, BTreeNode *sub){
	if (main->right != NULL)
		free(main->right);
		
	main->right = sub;
}

typedef int Data;
typedef struct _node{
	Data data;
	struct _node * next;
}Node;

typedef struct _listStack{
	Node * head;
} ListStack;

typedef ListStack Stack;
 
void StackInit(Stack * pstack){
	pstack->head = NULL;
}

int SIsEmpty(Stack * pstack){
	if(pstack->head == NULL)
		return 1;
	else
		return 0;	
}

void SPush(Stack * pstack, Data data){
	Node * newNode = (Node*)malloc(sizeof(Node));
	
	newNode->data = data;
	newNode->next = pstack->head;
	
	pstack->head = newNode;
}

Data SPop(Stack * pstack){
	Data rdata;
	Node * rnode;
	
	if(SIsEmpty(pstack)){
		printf("Stack Memory Error!");
		exit(-1);
	}
	
	rdata = pstack->head->data;
	rnode = pstack->head;
	
	pstack->head = pstack->head->next;
	free(rnode);
	
	return rdata;
}

Data SPeek(Stack * pstack){
	if(SIsEmpty(pstack)){
		printf("Stack Memory Error!");
		exit(-1);
	}
	
	return pstack->head->data;
}

BTreeNode * MakeExpTree(char exp[]){
	Stack stack;
	BTreeNode * pnode;
	
	int expLen = strlen(exp);
	int i;
	
	StackInit(&stack);
	
	for(i=0;i<expLen; i++){
		pnode = MakeBTreeNode();
		if(isdigit(exp[i])){
			SetData(pnode, exp[i]-'0');
		} else{
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack));
			SetData(pnode, exp[i]);
		}
		
		SPush(&stack, pnode);
	}
	
	return SPop(&stack);
}

int EvaluateExpTree(BTreeNode * bt){
	
}

void ShowNodeData(int data){
	if(0<=data && data<=9)	printf("%d ",data);
	else prinf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode * bt){
	PreorderTraverse(bt);
}

void ShowInfixTypeExp(BTreeNode * bt){
	InorderTraverse(bt);
}

void ShowPostfixTypeExp(BTreeNode * bt){
	PostorderTraverse(bt);
}

/*int main(void){
	BTreeNode * bt1 = MakeBTreeNode();
	BTreeNode * bt2 = MakeBTreeNode();
	BTreeNode * bt3 = MakeBTreeNode();
	BTreeNode * bt4 = MakeBTreeNode();
	BTreeNode * bt5 = MakeBTreeNode();
	BTreeNode * bt6 = MakeBTreeNode();
	BTreeNode * bt7 = MakeBTreeNode();
	
	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	SetData(bt5, 5);
	SetData(bt6, 6);
	SetData(bt7, 7);
	
	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);
	MakeRightSubTree(bt2, bt5);
	MakeLeftSubTree(bt3, bt6);
	MakeRightSubTree(bt3, bt7);
		
	printf("%d \n",GetData(bt1));
	printf("%d %d\n",GetData(GetLeftSubTree(bt1)),GetData(GetRightSubTree(bt1)));
	printf("%d %d ",GetData(GetLeftSubTree(GetLeftSubTree(bt1))), GetData(GetRightSubTree(GetLeftSubTree(bt1))));
	printf("%d %d\n",GetData(GetLeftSubTree(GetRightSubTree(bt1))), GetData(GetRightSubTree(GetRightSubTree(bt1))));
	
	printf("\n\n\n주소 출력\n\n\n");
	printf("%p \n",bt1);
	printf("%p %p\n",bt2,bt3);
	printf("%p %p ",bt4,bt5);
	printf("%p %p\n",bt6,bt7);
	
	return 0;
}*/


/*int main(void){
	BTreeNode *bt1 = MakeBTreeNode();
	BTreeNode *bt2 = MakeBTreeNode();
	BTreeNode *bt3 = MakeBTreeNode();
	BTreeNode *bt4 = MakeBTreeNode();
	BTreeNode *bt5 = MakeBTreeNode();
	BTreeNode *bt6 = MakeBTreeNode();
	BTreeNode *bt7 = MakeBTreeNode();
	
	SetData(bt1, 1); 
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	SetData(bt5, 5);
	SetData(bt6, 6);
	SetData(bt7, 7);

	
	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);
	MakeRightSubTree(bt2, bt5);
	MakeLeftSubTree(bt3, bt6);
	MakeRightSubTree(bt3, bt7);	
	
	//InorderTraverse(bt1);
	//printf("\n\n\n");
	
	PreorderTracerse(bt1);
	return 0;
}*/

int main(void){
	char exp[] = "12+7*";
	BTreeNode * eTree = MakeExpTree(exp);
	
	printf("전위 표기법의 수식: ");
	ShowPrefixTypeExp(eTree); printf("\n"); 
	
	printf("중위 표기법의 수식: ");
	ShowInfixTypeExp(eTree); printf("\n");
	
	printf("후위 표기법의 수식: ");
	ShowPostfixTypeExp(eTree); printf("\n");
	
	printf("연산의 결과: %d \n",EvaluateExpTree(eTree));
	
	return 0;
}

