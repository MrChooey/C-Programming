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

int pop(int stack[]) {
	stack[11]--;

	return stack[stack[11]];
}

void displayStack(int stack[]) {
	printf("Stack: ", stack[11]);
	for (int i = 0; i < stack[11]; i++) {
		printf("%d ", stack[i]);
	}
	printf("\n\n");
}

void getMethodStack(int *userInput) {
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

int stack() {
	int stack[MAX];
	int input;

	// current location
	stack[11] = 0;
	// size of stack
	stack[10] = 10;

	do {
		getMethodStack(&input);
		switch (input) {
			case 1:
				push(stack);
				printf("Number pushed!\n\n");
				break;
			case 2:
				printf("Number %d popped!\n\n", pop(stack));
				break;
			case 3:
				displayStack(stack);
				break;
			case 4:
				printf("Program Ended.");
				return 0;
			default:
				printf("Invalid option. Please try again.\n");
		}
	} while (1);

	return 0;
}

void getMethodQueue(int *userInput) {
	printf("|----------------|\n");
	printf("|      Menu\t |\n");
	printf("| 1. Enqueue\t |\n");
	printf("| 2. Dequeue\t |\n");
	printf("| 3. Show Queue\t |\n");
	printf("| 4. Exit\t |\n");
	printf("|----------------|\n");

	printf("Enter option: ");
	scanf("%d", userInput);
}

void getMethodList(int *userInput) {
	printf("|----------------|\n");
	printf("|      Menu\t |\n");
	printf("| 1. Add\t |\n");
	printf("| 2. Remove\t |\n");
	printf("| 3. Show List\t |\n");
	printf("| 4. Exit\t |\n");
	printf("|----------------|\n");

	printf("Enter option: ");
	scanf("%d", userInput);
}

void getOptions(int *option) {
	printf("|----------------|\n");
	printf("|      Menu\t |\n");
	printf("| 1. Stack\t |\n");
	printf("| 2. Queue\t |\n");
	printf("| 3. List\t |\n");
	printf("| 4. Exit\t |\n");
	printf("|----------------|\n");

	printf("Enter option: ");
	scanf("%d", option);
}

int main(void) {
	int option;

	do {
		getOptions(&option);
		switch (option) {
			case 1:
				stack();
				break;
			case 2:
				// queue();
				break;
			case 3:
				// list();
				break;
			case 4:
				printf("Program Ended.");
				return 0;
			default:
				printf("Invalid option. Please try again.\n");
		}
	} while(1);
}