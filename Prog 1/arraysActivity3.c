//Array activity 3
#include <stdio.h>
#include <math.h>

int main(void) {
	int number, i;
	int isPrime = 1;
	float root;

	printf("Enter a number: ");
	scanf("%d", &number);

	root = sqrt(number);

	for (i = 2; i <= root; i++) {
		if (number % i == 0) {
			isPrime = 0;
			break;
		}
	}