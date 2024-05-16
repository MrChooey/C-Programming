#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[500];

typedef struct {
	String Description;
	int priority;
} Task;

typedef struct node {
	int data;
	struct node *next;
} Node;

void getMode(int *choice) {
	printf("----------- TO DO LIST -----------\n\n");
	printf("Please select mode:\n\n");
	printf("1.) Input new task\n");
	printf("2.) View and edit to do list\n");
	printf("3.) Exit program\n\n");
	printf("----------------------------------\n\n");

	printf("Enter mode: ");
	scanf("%d", choice);

	printf("\n\n");
}

void inputMode() {
	int choice;

	printf("----------- TO DO LIST -----------\n\n");
	printf("")
}

void editMode() {

}

int main(void) {
	int choice;

	do {
		getMode(&choice);
		switch(choice) {
			case 1:
				inputMode();
				break;
			case 2:
				break;
			case 3:
				printf("Exiting program...");
				break;
			default:
				printf("Invalid input...!");
		}
	} while(choice != 3);


	return 0;
}