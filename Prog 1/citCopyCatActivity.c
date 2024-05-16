#include <stdio.h>

int main(void){
	int time;
	float carkmpm,distance;
	carkmpm = 50 * 0.01666666667;
	
	printf("Enter minutes: ");
	scanf("%d",&time);
	
	distance = carkmpm * time;
	printf("This is the distance you've traveled: %f",distance);
	
	return 0;
}
