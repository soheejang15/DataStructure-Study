#ifndef __AB_STACK_H__
#define __AB_STACK_H__

#define TRUE	1	// TRUE 1로 정의
#define FALSE	0	// FALSE 0으로 정의
#define STR_LEN	100 // STR_LEN (배열 길이) 100으로 정의

typedef int Data;	// int 자료형인 Data라는 자료형 정의

typedef struct _arrayStack { // 배열 기반 Stack 구조체 정의
	Data stackArray[STR_LEN];	// Stack인 배열의 길이 100
	int topIndex;	// Stac에 마지막으로 Data가 PUSH 된 인덱스 
}ArrayStack;	// 구조체 _arrayStack을 ArrayStack이라는 자료형으로 정의

typedef ArrayStack Stack;	// ArrayStack을 Stack 이라는 자료형으로 정의

void StackInit(Stack * pstack);	// Stack 초기화
int SIsEmpty(Stack * pstack);	// Stack이 비었는지 검사

void SPush(Stack * pstack, Data data);	// Stack PUSH 연산
Data SPop(Stack * pstack);	// Stack POP 연산
Data SPeek(Stack * pstack);	// Stack PEEK 연산

#endif // !__AB_STACK_H__
