#include <stdio.h>

struct info{
	int number;
	char name[10];
	int score[3];
	char grade[3];
}stu[3];

int main(void){
	int i, j;
	for (i=0;i<3;i++){
		printf("학번 이름 과목1 과목2 과목3 : ");
		scanf("%d %s",&stu[i].number,&stu[i].name);
		for(j=0;j<3;j++){
			scanf("%d",&stu[i].score[j]);
		}
	}
	
	for(i=0;i<3;i++){
	
		printf("%d %s",stu[i].number,stu[i].name);
		for(j=0;j<3;j++){
			printf(" %d",stu[i].score[j]);
			
			if(stu[i].score[j]>100){
				printf(" e");
			} 
			else if(stu[i].score[j]>=90){
				printf(" A");
			} 
			else if(stu[i].score[j]>=80){
				printf(" B");
			} 
			else if(stu[i].score[j]>=70){
				printf(" C");
			}
			else {
				printf(" F");
			} 
		}
		printf("\n");
	}			
}
