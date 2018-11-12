#include "ArrayBaseStack.h"
#include <stdio.h>
#include <stdlib.h>

void StackInit(Stack * pstack) {
	pstack->topIndex = -1;
}

int SIsEmpty(Stack * pstack) {
	if (pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data) {
	pstack->topIndex += 1;
	pstack->stackArray[pstack->topIndex] = data;
}

Data SPop(Stack * pstack) {
	int inx;
	
	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	inx = pstack->stackArray[pstack->topIndex];
	pstack->topIndex -= 1;
	
	return pstack->stackArray[inx];
}

Data SPeek(Stack * pstack);	// Stack PEEK ¿¬»ê