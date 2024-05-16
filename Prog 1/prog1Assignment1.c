#include <stdio.h>

int main(void){
	int x,y,limit;
	
	printf("Enter number of rows: ");
	scanf("%d",&limit);
	
	y=0;
	while(y<limit){
		
		x=0;
		while(x<y){
			printf("*");
			x++;
		}
		printf("\n");
		y++;
	}
	
	while(y>0){
		
		x=0;
		while(x<y){
			printf("*");
			x++;
		}
		printf("\n");
		y--;
	}
	
	return 0;
}
