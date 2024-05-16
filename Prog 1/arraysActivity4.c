//Array activity 4
#include <stdio.h>

int main(void) {
	int number[100];
	int finish = 0;
	int i, j;

	for (i = 0; i < 100; i++) {

		printf("Enter number %d: ", i + 1);
		scanf("%d", &number[i]);

		for (j = 0; j < i; j++) {
			if (number[j] == number[i]) {
				finish = 1;
				break;
			}
		}
		if (finish) {
			break;
		}
	}

	printf("%d is already in the array", number[i]);

	return 0;
}