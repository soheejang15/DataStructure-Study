#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void){
	int ans[3], cho[3];
	int count=0, i,j;
	int strike, ball;
	
	// 난수 발생 
		for (i=0;i<3;i++){
			srand(time(NULL));
			ans[i] = rand() % 9+1;
			for(j=0;j<i;j++){
				if(ans[i]==ans[j]){
					i--;
					break;
				}
			}  
		}
	
	//게임 시작 
	printf("Start Game!\n\n"); 
	
	while(1){ 
		strike = 0; ball = 0;
		
		// 숫자 선택 
		printf("3개의 숫자 선택 : ");
		for(i=0;i<3;i++) scanf("%d",&cho[i]);
		
		//입력받은 숫자 중복 여부 
		if(cho[0]==cho[1]||cho[0]==cho[2]||cho[1]==cho[2]){
		printf("같은 숫자를 중복사용할 수 없습니다.\n\n");
		continue;	
		}	
		
		// 입력 비교 
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(ans[i]==cho[j]){
					if(i==j) strike++;
					else ball++;
				}	 
			}
		}
		
		count++;
		printf("%d번째 도전 결과 : %dstrike %dball!\n\n", count, strike, ball);
		
		
		if(strike == 3) break;
	}
	
	printf("Game Over!\n %d번 도전",count);
	
}
