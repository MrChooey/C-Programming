#include <stdio.h>

int main(void){
	int width,height,i,j,k;
	
	printf("Enter height: ");
	scanf("%d",&height);
	
	printf("Enter width: ",&width);
	scanf("%d",&width);
	
	if (width % 2 == 1){
		k = width / 2;
		for (j=0;j < width;j++){
			if (j == k){
				printf("*");				
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
		
		for(i=0;i < height;i++){
			if (i == height-1){
				for(j=0;j < width;j++){
					printf("*");
				}
			}
			else {
				for(j=0;j < width;j++){
					if(j == 0 || j == width-1){
						printf(" ");
					}
					else {
						printf("*");
					}
				}		
				
			}
			printf("\n");
		}		
	}
	else {
		printf("Error: Characters of width is even");
	}

	
	return 0;
}