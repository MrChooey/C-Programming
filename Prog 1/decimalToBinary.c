//decimal to binary method 1

#include <stdio.h>

int main(void){
	int decimal,binary,greater_power;
	
	decimal = 76;
	binary = 0;
	greater_power = 1;
	
	while(greater_power < decimal){
		greater_power *= 2;
	}
	while(greater_power > 0){
		binary *= 10;
		if(greater_power <= decimal){
			binary += 1;
			decimal -= greater_power;
		}
		greater_power /= 2;
	}
	
	printf("%d",binary);
	
	return 0;
}
