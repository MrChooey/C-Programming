#include <stdio.h>
#define MAX 12

void push(int stack[]) {
	int num;

	if (stack[11] < stack[10]) {
		printf("Enter a number: ");
		scanf("%d", &num);

		stack[stack[11]] = num;
		stack[11]++;

	} else
		printf("Stack overflow...");
}

void pop(int stack[]) {
	if(stack[11] == 0) {
		printf("The stack is currently empty...\n\n");
		return;
	}

	stack[11]--;

	printf("Number %d popped!\n\n", stack[stack[11]]);
}

void displayStack(int stack[]) {
	printf("Stack: ", stack[11]);
	for (int i = 0; i < stack[11]; i++) {
		printf("%d ", stack[i]);
	}
	printf("\n\n");
}

void getMethod(int *userInput) {
	printf("|----------------|\n");
	printf("|      Menu\t |\n");
	printf("| 1. Push\t |\n");
	printf("| 2. Pop\t |\n");
	printf("| 3. Show Stack\t |\n");
	printf("| 4. Exit\t |\n");
	printf("|----------------|\n");

	printf("Enter option: ");
	scanf("%d", userInput);
}

int main(void) {
	int stack[MAX];
	int input;

	// current location
	stack[11] = 0;
	// size of stack
	stack[10] = 10;

	do {
		getMethod(&input);
		switch (input) {
			case 1:
				push(stack);
				printf("Number pushed!\n\n");
				break;
			case 2:
				pop(stack);
				break;
			case 3:
				displayStack(stack);
				break;
			case 4:
				printf("Program Ended.");
				return 0;
		}
	} while (1);
}