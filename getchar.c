#include <stdio.h>
#include <stdlib.h>

int main(){
	char myWord[10];
	char temp;

	printf("Enter a word: ");
	scanf("%10s", myWord);

	while(getchar() != '\n'){}

	scanf("%c", &temp);
	return 0;
}