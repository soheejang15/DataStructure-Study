#include <stdio.h>
#include <string.h>

struct Person {
	char name[20];
	int age;
	char address[100];
}class[2];

int main(void){
	//struct Person p1;
	/*strcpy(p1.name,"장소희");
	p1.age = 17;
	strcpy(p1.address,"soheejjang02@naver.com");
	*/
	
	//struct Person p1 = {"장소희",17,"soheejjang02@naver.com"};
	strcpy(class[0].name , "장소희");
	class[0].age = 17;
	strcpy(class[0].address , "soheejjang02@naver.com");
	
	//struct Person p2;
	/*strcpy(p2.name, "최소영");
	p2.age = 17;
	strcpy(p2.address,"ruby020415@naver.com"); 
	*/
	
	//struct Person p2 = {"최소영",17,"ruby020415@naver.com"};
	
	strcpy(class[1].name , "최소영");
	class[1].age = 17;
	strcpy(class[1].address , "ruby020415@naver.com");
	
	//printf("p1 information\n%s\n%d\n%s\n\n",p1.name,p1.age,p1.address);	
	//printf("p2 information\n%s\n%d\n%s",p2.name,p2.age,p2.address);
	
	printf("p1 information\n%s\n%d\n%s\n\n",class[0].name,class[0].age,class[0].address);
	printf("p2 information\n%s\n%d\n%s\n\n",class[1].name,class[1].age,class[1].address);
}
