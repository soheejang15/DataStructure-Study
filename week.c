#include <stdio.h>

int main(void){
	int i;
	char week[7][3] = {"월","화","수","목","금","토","일"};
	
	for (i=0;i<7;i++){
		printf("%s\n",week[i]);
	}
}
