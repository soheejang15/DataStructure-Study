#include <stdio.h>
#include <stdlib.h>

// int 타입을 가지는 BTData 타입을 선언 
typedef int BTData;

// 이진트리의 노드를 구조체로 선언. 
//data/ left link (포인터) / right link (포인터)  
typedef struct _bTreeNode{
	BTData data;
	struct _bTreeNode * left;
	struct _bTreeNode * right;
}BTreeNode;


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

int main(void){
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
}

