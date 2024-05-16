#include <stdio.h>

/*int addition(int num1, int num2, int result){
	;
	
	printf("Enter first number: ");
	scanf("%d",&num1);
	printf("Enter second number: ");
	scanf("%d",&num2);
			
	result = num1 + num2;
			
	printf("%d + %d = %d",num1,num2,result);
	
	return addition;
}*/

int main(void){
	int num1,num2,result;
	int mode;
	
	printf("--- BASIC CALCULATOR ---\n");
	printf("a.) Addition\n");
	printf("b.) Subtraction\n");
	printf("c.) Multiplication\n");
	printf("d.) Division\n");
	printf("------------------------\n");
	printf("Enter mode of calculation (a-d): ");
	scanf("%d",&mode);
	
	switch (mode){
		case 1:	
			printf("Enter first number: ");
			scanf("%d",&num1);
			printf("Enter second number: ");
			scanf("%d",&num2);
			
			result = num1 + num2;
			
			printf("%d + %d = %d",num1,num2,result);
			
			break;
		case 'b':
			printf("Enter first number: ");
			scanf("%d",&num1);
			printf("Enter second number: ");
			scanf("%d",&num2);
			
			result = num1 - num2;
			
			printf("%d - %d = %d",num1,num2,result);
			break;
		case 'c':
			printf("Enter first number: ");
			scanf("%d",&num1);
			printf("Enter second number: ");
			scanf("%d",&num2);
			
			result = num1 * num2;
			
			printf("%d x %d = %d",num1,num2,result);
			break;
		case 'd':
			printf("Enter first number: ");
			scanf("%d",&num1);
			printf("Enter second number: ");
			scanf("%d",&num2);
			
			result = num1 / num2;
			
			printf("%d / %d = %d",num1,num2,result);
			break;
		default:
			printf("Error: Option not found");
	}
	
	return 0;
}
