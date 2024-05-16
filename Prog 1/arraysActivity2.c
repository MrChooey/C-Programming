//Array activity 2
#include <stdio.h>

int main(void) {
	int numbers[50];
	int i, element;

	printf("Enter num of elements: ");
	scanf("%d", &element);

	for (i = 0; i < element; i++) {
		printf("Input element %d: ", i + 1);
		scanf("%d", &numbers[i]);
	}

	printf("Values in reverse are: ");

	for (; element > 0; element--) {
		printf("%d ", numbers[element - 1]);
	}

	return 0;
}