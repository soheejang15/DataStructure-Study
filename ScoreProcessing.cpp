#include <stdio.h>
#include <string.h>

struct info{
	int number;
	char name[10];
	int score[3];
	char grade[3];
}stu[3];

int main(void){
	int i, j;
	for (i=0;i<1;i++){
		printf("학번 이름 과목1 과목2 과목3 : ");
		scanf("%d %s",&stu[i].number,&stu[i].name);
		for(j=0;j<3;j++){
			scanf("%d",&stu[i].score[j]);
		}
	}
	
	for(i=0;i<1;i++){
		for(j=0;j<3;j++){
			if(stu[i].score[j]>100){
				stu[i].grade[j]="e ";
			} 
			else if(stu[i].score[j]>=90){
				stu[i].grade[j]="A ";
			} 
			else if(stu[i].score[j]>=80){
				stu[i].grade[j]="B ";
			} 
			else if(stu[i].score[j]>=70){
				stu[i].grade[j]="C ";
			}
			else {
				stu[i].grade[j]="F ";
			} 
		}
	}
	
	printf("%d %s",stu[0].number,stu[0].name);
		for(j=0;j<3;j++){
			printf("%d",stu[0].score[j]);
		}
		for(j=0;j<3;j++){
			printf("%s",stu[0].grade[j]);
		}
}
