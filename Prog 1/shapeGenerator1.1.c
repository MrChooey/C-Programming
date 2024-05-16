#include <stdio.h>

    /*
	
	Alright, you can look at this code - but only if you solve this maze within 10 seconds. 
	Fair is fair.						

	                                                                    Start.
	
	aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa   a
	8   8               8               8           8                   8   8
	8   8   aaaaaaaaa   8   aaaaa   aaaa8aaaa   aaaa8   aaaaa   aaaaa   8   8
	8               8       8   8           8           8   8   8       8   8
	8aaaaaaaa   a   8aaaaaaa8   8aaaaaaaa   8aaaa   a   8   8   8aaaaaaa8   8
	8       8   8               8           8   8   8   8   8           8   8
	8   a   8   8aaaaaaaa   a   8   aaaaaaaa8   8aaa8   8   8aaaaaaaa   8   8
	8   8               8   8   8       8           8           8       8   8
	8   8aaaaaaaaaaaaaaa8aaa8   8aaaa   8   aaaaa   8aaaaaaaa   8   aaaa8   8
	8           8       8   8       8   8       8           8   8           8
	8   aaaaa   8aaaa   8   8aaaa   8   8aaaaaaa8   a   a   8   8aaaaaaaaaaa8
	8       8       8   8   8       8       8       8   8   8       8       8
	8aaaaaaa8aaaa   8   8   8   aaaa8aaaa   8   aaaa8   8   8aaaa   8aaaa   8
	8           8   8           8       8   8       8   8       8           8
	8   aaaaa   8   8aaaaaaaa   8aaaa   8   8aaaa   8aaa8   aaaa8aaaaaaaa   8
	8   8       8           8           8       8   8   8               8   8
	8   8   aaaa8aaaa   a   8aaaa   aaaa8aaaa   8   8   8aaaaaaaaaaaa   8   8
	8   8           8   8   8   8   8           8               8   8       8
	8   8aaaaaaaa   8   8   8   8aaa8   8aaaaaaa8   aaaaaaaaa   8   8aaaaaaa8
	8   8       8   8   8           8           8   8       8               8
	8   8   aaaa8   8aaa8   aaaaa   8aaaaaaaa   8aaa8   a   8aaaaaaaa   a   8
	8   8                   8           8               8               8   8
	8   8aaaaaaaaaaaaaaaaaaa8aaaaaaaaaaa8aaaaaaaaaaaaaaa8aaaaaaaaaaaaaaa8aaa8
	
	End.
	
    */

int main(void){
	char mode;
	int x,y,y2,i,j,k,limit,rows,rows1,width,height;
	
	printf("----- Welcome to Ron's Shape Generator! -----\n");
	printf("a.) Right Triangle\n");
	printf("b.) Pyramid\n");
	printf("c.) Half Diamond\n");
	printf("d.) Diamond\n");
	printf("e.) Empty Box\n");
	printf("f.) Skyscraper\n");
	printf("---------------------------------------------\n");
	printf("Choose which shape to print: ");
	scanf("%c",&mode);
	printf("\n");
	
	switch (mode){
		case 'a':
			printf("Enter number of rows: ");
			scanf("%d",&limit);
			
			y=0;
			while(y<limit+1){
				
				x=0;
				while(x<y){
					printf("*");
					x++;
				}
				printf("\n");
				y++;
			}
			break;
			
		case 'b':
			printf("Enter number of rows: ");
			scanf("%d",&rows);
			
			for (int i = 1; i <= rows; i++){
				for (int j = 1; j <= rows - i; j++){
					printf(" ");
				}
				for (int k = 1; k <= i; k++){
					printf("*");
				}
				for (int l = 1; l < i; l++){
					printf("*");
				}
				printf("\n");
			}
			break;
		
		case 'c':
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
			break;
			
		case 'd':
			printf("Enter number of rows: ");
			scanf("%d",&rows);
			
			rows1 = rows;
			y2 = 1;
			for(; rows>1; rows--,y2++){
				for(y=1; y<=rows; y++){
					printf(" ");
				}
				for(x=1; x<=y2; x++){
					printf("* ");
				}
				printf("\n");
			}
			
			//reversing this to create a diamnond
			
			for(; rows<=rows1; rows++,y2--){
				for(y=1; y<=rows; y++){
					printf(" ");
				}
				for(x=1; x<=y2; x++){
					printf("* ");
				}
				printf("\n");
			}
			break;
			
		case 'e':
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
			break;
			
		case 'f':
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
			break;	
	}
	
	return 0;
}
