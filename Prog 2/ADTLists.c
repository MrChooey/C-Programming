// TODO: Add Queue. Need sorted insertion for list.
#include <stdio.h>
#include <stdlib.h>
#define MAX 12

// STACK FUNCTIONS!!
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
	printf("Stack: ");
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

	printf("\n\n !! Stack initialized. !!\n\n");

	do {
		getMethodStack(&input);
		switch (input) {
			case 1:
				push(stack);
				printf("\n\n!! Number Pushed !!\n\n");
				break;
			case 2:
				printf("\n\n!! Number %d popped !!\n\n", pop(stack));
				break;
			case 3:
				displayStack(stack);
				break;
			case 4:
				printf("\n\n!! Stack Program Ended !!\n\n");
				return 0;
			default:
				printf("Invalid option. Please try again.\n");
		}
	} while (1);

	return 0;
}

// QUEUE FUNCTIONS!!
// LIST FUNCTIONS!!
struct node {
	int data;
	struct node *next;
};

void printThis(struct node *traverse) {
	printf("Here is your current list: \n");
	while (traverse->next != NULL) {
		traverse = traverse->next;
		printf("%d ", traverse->data);
	}
	printf("\n\n");
}

void insertNode(struct node *traverse, int num) {
	struct node *new = (struct node *)malloc(sizeof(struct node));

	new->data = num;
	new->next = NULL;

	if (traverse->next == NULL) {
		traverse->next = new;
	} else {
		while (traverse->next != NULL) traverse = traverse->next;
		traverse->next = new;
	}
	printf("\n\n");
}

void deleteNodeByValue(struct node *traverse, int num) {
	struct node *temp;

	while (traverse->next != NULL) {
		temp = traverse;
		traverse = traverse->next;
		if (traverse->data == num) {
			temp->next = traverse->next;
			free(traverse);
			traverse = temp;
			printf("Number deleted.\n\n");
			return;
		}
	}
	printf("Number not found.\n\n");
}

int list() {
	struct node *head = (struct node *)malloc(sizeof(struct node));
	head->next = NULL;

	int num;
	int userInput;

	printf("\n\n !! List initialized. !!\n\n");

	do {
		getMethodList(&userInput);
		switch (userInput) {
			case 1:
				printf("Enter a number for your list: ");
				scanf("%d", &num);
				insertNode(head, num);
				break;
			case 2:
				printf("Enter a number to delete: ");
				scanf("%d", &num);
				deleteNodeByValue(head, num);
				break;
			case 3:
				printThis(head);
				break;
			case 4:
				printf("\n\n!! Program Ended !!\n\n");
				return 0;

			default:
				printf("Invalid option. Please try again.\n");
				break;
		}
	} while (1);
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
				list();
				break;
			case 4:
				printf("\n\n!! Program Ended !!\n\n");
				return 0;
			default:
				printf("Invalid option. Please try again.\n");
		}
	} while (1);
}