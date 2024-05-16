#include <stdio.h>

int main(void){
	int remainder,number,condition=0;
	
	printf("Enter a number: ");
	scanf("%d",&number);
	
	while (number > 0){
		remainder = number % 10;
		if (remainder > 3){
			printf("%d\n",remainder);
			condition += 1;
		}
		else {
		}				
		number /= 10;
	}
	
	if (condition == 0){
		printf("none");
	}
	else {
	}
	
	return 0;
}
