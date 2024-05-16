#include <stdio.h>

int main(void){
	int width,height,x,y;
	
	printf("Enter width: ");
	scanf("%d",&width);
	
	printf("Enter height: ");
	scanf("%d",&height);
	
	for(y=1;y<=height;y++){
		if (y == height || y == 1){
			for(x=1;x<=width;x++){
				printf("#");
			}	
		}
		else {
			for(x=1;x<=width;x++){
				if (x < width && x > 1){
					printf(" ");
				}
				else {
					printf("#");
				}
			}
		}
		printf("\n");
	}
	
	return 0;
}
