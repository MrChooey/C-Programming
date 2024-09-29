#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct node {
	int data;
	struct node *next;
} *NodePtr;

typedef NodePtr Dictionary[MAX];

void initDict(Dictionary A);
int hash(int data);
void insert(Dictionary A, int data);
bool inDict(Dictionary A, int data);
void delete(Dictionary A, int data);
void printDict(Dictionary A);


int main(void) {
	Dictionary D;

	initDict(D);
	
	// Row 0
	insert(D, 10);
	insert(D, 20);
	insert(D, 30);

	//Row 1
	insert(D, 11);
	insert(D, 41);

	//Row 2

	// Row 3
	insert(D, 3);
	insert(D, 23);
	insert(D, 53);
	insert(D, 123);

	// Row 4
	insert(D, 44);
	insert(D, 24);
	insert(D, 14);

	// Row 5
	insert(D, 5);
	insert(D, 75);

	// Row 6
	insert(D, 6);
	insert(D, 46);
	insert(D, 86);

	// Row 7
	insert(D, 77);
	insert(D, 97);
	insert(D, 27);

	// Row 8
	insert(D, 28);

	// Row 9
	insert(D, 89);

	int num = 46;
	printf("Number %d %s in dictionary...\n", num, (inDict(D, num)) ? "is" : "is not");

	printDict(D);

	delete(D, 46);
	delete(D, 97);
	delete(D, 27);
	delete(D, 86);
	delete(D, 123);

	printf("\n");

	printDict(D);

	return 0;
}

void initDict(Dictionary A) {
	for(int i = 0; i < MAX; i++) {
		A[i] = NULL;
	}
}

int hash(int data) {
	return data % MAX;
}

void insert(Dictionary A, int data) {
	int index = hash(data);

	NodePtr *trav;

	for (trav = &A[index]; *trav != NULL && (*trav)->data != data; trav = &(*trav)->next);

	if (*trav == NULL) {
		NodePtr temp = (NodePtr)malloc(sizeof(struct node));

		if (temp != NULL) {
			temp->data = data;
			temp->next = NULL;
			*trav = temp;
		}
	}
}

bool inDict(Dictionary A, int data) {
	int index = hash(data);

	NodePtr trav;

	for (trav = A[index]; trav != NULL && trav->data != data; trav = trav->next);

	return (trav != NULL) ? true : false;
}

void delete(Dictionary A, int data) {
	int index = hash(data);

	NodePtr *trav;

	for (trav = &A[index]; *trav != NULL && (*trav)->data != data; trav = &(*trav)->next);

	if (*trav != NULL) {
		NodePtr temp;
		temp = *trav;
		*trav = temp->next;
		free(temp);
	}
}

void printDict(Dictionary A) {
	for (int i = 0; i < MAX; i++) {
		printf("\nRow %d: ", i);

		for (NodePtr trav = A[i]; trav != NULL; trav = trav->next) {
			printf("%d ", trav->data);
		} 
	}
}