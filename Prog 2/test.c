#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} nodePtr, *List;

void printThis(List trav) {
	printf("Here is your current list: \n");
	for (; trav != NULL; trav = trav->next) {
		printf(" %d", trav->data);
	}
	printf("\n\n");
}

void insertLast(List *A, int num) {
	List *trav;

	for (trav = A; *trav != NULL; trav = &(*trav)->next);

	List new = malloc(sizeof(nodePtr));
	new->data = num;
	new->next = NULL;
	*trav = new;
}

int main(void) {
	List head = NULL;

	insertLast(&head, 1);
	insertLast(&head, 2);
	insertLast(&head, 3);

	printThis(head);

	return 0;
}