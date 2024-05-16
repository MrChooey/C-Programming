#include <stdio.h>

int main(void){
	int width,height,i,j,k;
	
	printf("Enter height: ");
	scanf("%d",&height);
	
	printf("Enter width: ",&width);
	scanf("%d",&width);
	
	k = (width / 2) + 1;
	
	if (width % 2 == 1){
		for (j=0;j < width;j++){
			if (j == k){
				printf("*");				
			}
			else {
				printf(" ");
			}
		}		
	}
	else {
		for (j=0;j < width+2;j++){
			if (j == k-1 || j == k){
				printf("*");
			}
			else {
				printf(" ");
			}
		}
	}

	printf("\n");
		
	for(i=0;i < height-1;i++){
		if (i == height-2){
			for(j=0;j < width+2;j++){
				printf("*");
			}
		}
		else {
			for(j=0;j < width+2;j++){
				if(j == 0 || j == width+1){
					printf(" ");
				}
				else {
					printf("*");
				}
			}		
		}
		printf("\n");
	}				


	
	return 0;
}
