#include <stdio.h>

int main(void){
	char variable;
	
	printf("Enter capital letter here: ");
	scanf("%c", &variable);
	
	variable += 32;
	
	printf("The small letter is: %c", variable);
	
	return 0;
}
