// TODO: Needs Sorted Insertion
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void displayMenu(int *userInput) {
	printf("|--------------------|\n");
	printf("|  Linked List Demo  |\n");
	printf("| 1. Print           |\n");
	printf("| 2. Insert          |\n");
	printf("| 3. Delete          |\n");
	printf("| 4. Exit            |\n");
	printf("|--------------------|\n\n");

	printf("Enter option: ");
	scanf("%d", userInput);
}

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

// void insertNodeSorted(struct node *traverse, int num) {
// 	struct node *new = (struct node *)malloc(sizeof(struct node));
// 	struct node *temp;

// 	new->data = num;
// 	new->next = NULL;


// 	if (traverse->next == NULL) {
// 		traverse->next = new;
// 	} else {
// 		while (traverse->next != NULL) traverse = traverse->next;
// 		traverse->next = new;
// 	}
// 	printf("\n\n");
// }

// void deleteNodeAtEnd() {
	
// }

void deleteNodeByValue(struct node *traverse, int num) {
	struct node *temp;
	int status = 0;

	while (traverse->next != NULL) {
		temp = traverse;
		traverse = traverse->next;
		if (traverse->data == num) {
			temp->next = traverse->next;
			free(traverse);
			traverse = temp;
			status = 1;

			break;
		}
	}
	if (!status) printf("Number not found.\n\n");
	else printf("Number/s deleted.\n\n");
}

int main(void) {
	struct node *head = (struct node*) malloc(sizeof(struct node));
	head->next = NULL;

	int num;
	int userInput;

	do {
		displayMenu(&userInput);
		switch (userInput) {
			case 1:
				printThis(head);
				break;
			case 2:
				printf("Enter a number for your list: ");
				scanf("%d", &num);
				insertNode(head, num);
				break;
			case 3:
				printf("Enter a number to delete: ");
				scanf("%d", &num);
				deleteNodeByValue(head, num);
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