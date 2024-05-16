#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} nodeType, *nodePtr;

void displayNode(nodePtr list) {
	while (list != NULL) {
		printf("%d, ", list->data);
		list = list->next;
	}
	printf("\n");
}

void insertFront(nodePtr *list, int num) {
	nodePtr temp = malloc(sizeof(nodeType));

	temp->data = num;
	temp->next = *list;
	*list = temp;
}

void insertRear(nodePtr *list, int num) {
	nodePtr temp = malloc(sizeof(nodeType));
	nodePtr *curr = list;
	if (temp != NULL) {
		temp->data = num;
		temp->next = NULL;
		while (*curr != NULL) {
			curr = &(*curr)->next;
		}
		*curr = temp;
	}
}

void insertMiddle(nodePtr *list, int num, int pos) {
}

void insertSorted(nodePtr *list, int num) {
	nodePtr temp = malloc(sizeof(nodeType));
	nodePtr curr = *list;
	nodePtr key = temp->data;

	if (list == NULL || key < curr->data) {
		insertFront(list, num);
	} else {
		while (curr != NULL && curr->next->data < key) {
			curr = curr->next;
			temp->next = curr->next;
			curr->next = temp;
		}
		return;
	}
}

int main() {
	nodePtr head = NULL;
	int num, choice, pos;

	do {
		printf("1. Insert Front\n");
		printf("2. Insert Rear\n");
		printf("3. Insert Middle\n");
		printf("Enter Choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				printf("Enter number to insert: ");
				scanf("%d", &num);
				insertFront(&head, num);
				displayNode(head);
				break;
			case 2:
				printf("Enter number to insert: ");
				scanf("%d", &num);
				insertRear(&head, num);
				displayNode(head);
				break;
			case 3:
				printf("Enter a number to insert: ");
				scanf("%d", &num);
				printf("Enter the position: ");
				scanf("%d", &pos);
				insertMiddle(&head, num, pos);
				displayNode(head);
				break;
			default:
				printf("Invalid choice\n");
		}
	} while (choice != 3);

	return 0;
}