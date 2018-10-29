#include <stdio.h>

int SearchTargetIndex(int arr[], int len, int target){
	int first = 0, last = len-1;
	
	while(first<=last){
		
		int mid = (first+last)/2;
		if(arr[mid] == target) return mid;
		
		else{
			if(arr[mid] < target) first = mid + 1;
			else last = mid -1;
		}
		
	}
	return -1;
	
} 

int main(void){
	int arr[] = {1,3,8,11,15,17,20,25,30};
	int target, start, end, index;
	
	// target값 설정 
	printf("target 값 입력 : ");
	scanf("%d",&target);
	
	index = SearchTargetIndex(arr, sizeof(arr)/sizeof(int), target);
	
	if(index == -1) printf("배열 안에 해당 target이 존재하지 않습니다.");
	else printf("target의 인덱스는 %d입니다.", index); 
}
