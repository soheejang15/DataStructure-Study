#include <stdio.h>
#include <wchar.h>

int main(void){
	int i;
	wchar week[7] = {L'월',L'화',L'수',L'목',L'금',L'토',L'일'};
	for (i=0;i<7;i++){
		wprintf(L"%c ",week[i]);
	}
}
