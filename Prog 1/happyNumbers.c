#include <stdio.h>
#include <stdbool.h>

bool isHappy(int num) {
	int num1, digit, sum;

	num1 = num;

	while (num1 != 1 && num1 != 4) {
		sum = 0;
		while (num1 > 0) {
			digit = num1 % 10;
			sum += digit * digit;
			num1 /= 10;
		}
		num1 = sum;
	}

	return num1 == 1 ;
}

int main(void) {
	int num;

	printf("Enter a number: ");
	scanf("%d", &num);

	if (isHappy(num)) {
		printf("%d is a happy number.\n", num);
	} else {
		printf("The number is not a happy number.\n");
	}

	return 0;
}