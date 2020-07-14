#include <stdio.h>

int main(){
	int q = 1;
	for(int i = 0; i < 2; i++){
		printf("%d %d\n", i, (q=q*++q));
	}

	return 0;
}