#include <stdio.h>

union student{
	int id;
	int no;
}s1;

int main(void){
	s1.id =1517;
	printf("%d %d\n",s1.id,s1.no);
	s1.no=17;
	printf("%d %d\n",s1.id,s1.no);
}
