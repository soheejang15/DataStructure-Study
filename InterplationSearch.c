#include <stdio.h>

int SearchTargetIndex(int arr[], int first, int last, int target){
	int mid = ((double)(target-arr[first])/(arr[last]-arr[first])*(last-first))+first;
	printf("%d\n",mid);
	
	if(first > last) return -1;
	
	if(arr[mid] == target) return mid;
	else if(target < arr[mid]) return SearchTargetIndex(arr, first, mid-1, target);
	else return SearchTargetIndex(arr, mid+1, last, target);
	
} 

int main(void){
	int arr[] = {1,3,8,11,15,17,20,25,30};
	int target, start, end, index;
	
	// target값 설정 
	printf("target 값 입력 : ");
	scanf("%d",&target);
	
	index = SearchTargetIndex(arr, 0, sizeof(arr)/sizeof(int)-1, target);
	
	if(index == -1) printf("배열 안에 해당 target이 존재하지 않습니다.");
	else printf("target의 인덱스는 %d입니다.", index); 
}
