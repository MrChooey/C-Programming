//decimal to binary method 2

#include <stdio.h>

/*
76 % 2 = 0
76 / 2 = 38 % 2 = 0
38 / 2 = 19 % 2 = 1
19 / 2 = 4 % 2 = 0
4 / 2 = 2 % 2 = 0
2 /2 = 1 % 2 = 1

1001100
*/

int main(void){
	int decimal,binary,position;
		
	binary = 0;
	position = 1;
	
	printf("Enter decimal number: ");
	scanf("%d",&decimal);
	
	while(decimal > 0){
		binary += (decimal % 2) * position;
		decimal /= 2;
		position *= 10;
	}
	
	printf("%d",binary);
	
	return 0;
}
