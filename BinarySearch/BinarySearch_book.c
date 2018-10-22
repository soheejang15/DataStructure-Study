#include <stdio.h>

int BSearch(int ar[], int len, int target){
	int first = 0;	// 탐색 대상의 시작 인덱스 값
	int last = len-1; // 탐색 대상의 마지막 인덱스 값
	int mid;
	
	while(first <= last){
		mid = (first + last)/2;	// 탐색 대상의 중앙 찾기 
		
		if(target == ar[mid]){	// 탐색 대상이 타겟과 같을 때 
			return mid;	// 인덱스 값 반환 
		}
		
		else{
			if(target<ar[mid]){	// 타켓이 탐색 대상 보다 작을 때 
				last = mid-1;	// 탐색 배열의 last 값을 mid-1
			}
			else{	// 타겟이 탐색 대상 보다 클 때 
				first = mid+1;	// 탐색 배열의 first 값을 mid+1 
			} 
		}
	} 
	return -1;	// 타겟이 탐색 대상 내에 없을 때 
}

int main(void){
	int arr[]={1,3,5,7,9};
	int idx;
	
	idx = BSearch(arr, sizeof(arr)/sizeof(int),7 );
	if (idx==-1){
		printf("배열 내에 타겟이 존재하지 않습니다.\n");
	}
	else{
		printf("타켓의 인덱스 번호는 %d입니다.\n",idx);
	}
	
	idx = BSearch(arr, sizeof(arr)/sizeof(int),4 );
	if (idx==-1){
		printf("배열 내에 타겟이 존재하지 않습니다.\n");
	}
	else{
		printf("타켓의 인덱스 번호는 %d입니다.\n",idx);
	}
} 
