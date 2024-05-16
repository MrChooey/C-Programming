#include <stdio.h>

int main(void){
	int totalmeters,nextmeters;
	float initialcost,totalcost,addcost;
	initialcost = 40;
	addcost = 2.50;
	nextmeters = 200;
	
	printf("Enter the distance traveled(meters): ");
	scanf("%d",&totalmeters);
	
	totalcost = initialcost + (((totalmeters-250) / nextmeters) * addcost);
	if (totalmeters <= 250){
		printf("Total cost: Php%.2f",initialcost);
	}
	else{
		printf("Total cost: Php%.2f",totalcost);
	}
	
	return 0;
}
