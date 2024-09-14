#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} *List;

void initList(List *L);
void insertFirst(List *L, int x);
void insertLast(List *L, int x);
void insertSorted(List *L, int x);
void displayList(List L);
void deleteData(List *L, int x);
void deleteLast(List *L);  //
void deleteFirst(List *L);

int main(void) {
	List L;

	initList(&L);

	printf("Insert First: ");

	insertLast(&L, 1);
	insertLast(&L, 2);
	insertLast(&L, 4);
	insertLast(&L, 5);
	insertLast(&L, 6);

	displayList(L);

	printf("\n");

	printf("Insert Sorted: ");

	insertSorted(&L, 3);

	displayList(L);

	printf("\n");

	printf("Delete First: ");

	deleteFirst(&L);

	displayList(L);

	printf("\n");

	printf("Insert First: ");

	insertFirst(&L, 1);

	displayList(L);

	printf("\n");

	printf("Delete Data: ");

	deleteData(&L, 5);

	displayList(L);

	return 0;
}

void initList(List *L) {
	*L = NULL;
}

void insertFirst(List *L, int x) {
	List temp = (List)malloc(sizeof(struct node));
	if (temp != NULL) {
		temp->data = x;
		temp->next = *L;
		*L = temp;
	}
}

void insertLast(List *L, int x) {
	List temp = (List)malloc(sizeof(struct node));
	if (temp != NULL) {
		List *trav;
		for (trav = L; *trav != NULL; trav = &(*trav)->next);
		temp->data = x;
		temp->next = NULL;
		*trav = temp;
	}
}

void insertSorted(List *L, int x) {
	List temp = (List)malloc(sizeof(struct node));
	if (temp != NULL) {
		List *trav;
		for (trav = L; *trav != NULL && (*trav)->data < x; trav = &(*trav)->next);
		temp->data = x;
		temp->next = *trav;
		*trav = temp;
	}
}

void deleteFirst(List *L) {
	if (*L != NULL) {
		List temp;
		temp = *L;
		*L = temp->next;
		free(temp);
	}
}

void deleteData(List *L, int x) {
	List *trav;
	for (trav = L; *trav != NULL && (*trav)->data != x; trav = &(*trav)->next);

	if (*trav != NULL) {
		List temp;
		temp = *trav;
		*trav = temp->next;
		free(temp);
	}
}

void displayList(List L) {
	List trav;
	for (trav = L; trav != NULL; trav = trav->next) {
		printf("%d ", trav->data);
	}
}
