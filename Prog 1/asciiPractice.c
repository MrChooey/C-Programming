#include <stdio.h>

int main(void){
	char variable;
	
	printf("Enter number here: ");
	scanf("%d", &variable);
	
	printf("**********************\n");
	printf("* The number:    %3d *\n", variable);
	printf("* The character: %3c *\n", variable);
	printf("**********************");
	
	return 0;
}
