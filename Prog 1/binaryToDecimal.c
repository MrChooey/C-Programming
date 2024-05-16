#include <stdio.h>

int main(void){
	int decimal,binary,position;
	
	decimal = 0;
	position = 1;
	
	printf("Enter binary number: ");
	scanf("%d",&binary);
	
	for (;binary > 0;binary /= 10, position *= 2){
		decimal += (binary % 10) * position;
	}
	
	printf("%d",decimal);
	
	return 0;
}
