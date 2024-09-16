#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} *List;

void initList(List *L);
void push(List *L, int x);
void pop(List *L);
void print(List L);

int main(void) {
	List L;

	initList(&L);

	push(&L, 1);
	push(&L, 2);
	push(&L, 3);
	push(&L, 4);
	push(&L, 5);
	push(&L, 6);

	printf("Pushed Elements: ");
	print(L);

	pop(&L);
	pop(&L);
	pop(&L);

	printf("\nPopped Elements: ");
	print(L);

	return 0;
}

void initList(List *L) {
	*L = NULL;
}

void push(List *L, int x) {
	List temp = (List)malloc(sizeof(struct node));
	if (temp != NULL) {
		temp->data = x;
		temp->next = *L;
		*L = temp;
	}
}

void pop(List *L) {
	if (*L != NULL) {
		List temp = *L;
		*L = temp->next;
		free(temp);
	}
}

void print(List L) {
	for (List trav = L; trav != NULL; trav = trav->next) {
		printf("%d ", trav->data);
	}
}