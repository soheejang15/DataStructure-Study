#include <stdio.h>

typedef struct _empInfo {
	char name[20];
	int empNum;
	int age;
}EmpInfo;

int GetHashValue(int num) {
	return num - 1400;
}

int main(void) {
	EmpInfo empInfoArr[18];
	EmpInfo per[4];
	EmpInfo p[4];

	int i;

	for (i = 0; i < 4; i++) {
		scanf("%s %d %d", per[i].name, &per[i].empNum, &per[i].age);
	}

	for (i = 0; i < 4; i++) {
		empInfoArr[GetHashValue(per[i].empNum)] = per[i];
	}

	for (i = 0; i < 4; i++) {
		p[i] = empInfoArr[GetHashValue(per[i].empNum)];
		printf("이름 : %s 학번 : %d 나이 : %d\n", p[i].name, p[i].empNum, p[i].age);
	}
}
