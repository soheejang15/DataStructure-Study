#include "ListBaseStack.h"
#include <stdio.h>
#include <stdlib.h>

void StackInit(Stack * pstack) {
	pstack->head = NULL;
}

int SIsEmpty(Stack * pstack){
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pstack->head;

	pstack->head = newNode;
}

Data SPop(Stack * pstack) {
	Data data;
	Node * pnode;

	if (SIsEmpty(pstack)) {
		printf("Stack Memeory Error!");
		exit(-1);
	}

	data = pstack->head->data;
	pnode = pstack->head;

	pstack->head = pstack->head->next;
	free(pnode);
	return data;
}
Data SPeek(Stack * pstack) {
	if (SIsEmpty(pstack)) {
		printf("Stack Memeory Error!");
		exit(-1);
	}

	return pstack->head->data;
}