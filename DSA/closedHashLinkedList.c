#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef int Dictionary[MAX];

typedef enum {
	EMPTY = -1,
	DELETED = -2
} Status;

void initDict(Dictionary A);
int hash(int data);
void insert(Dictionary A, int data);
void delete(Dictionary A, int data);
bool isMember(Dictionary A, int data);
void printDict(Dictionary A);
int searchLength(Dictionary A);

int main(void) {
	Dictionary D;

	initDict(D);

	insert(D, 10);
	insert(D, 23);
	insert(D, 32);
	insert(D, 55);
	insert(D, 78);
	insert(D, 33);

	printDict(D);

	delete(D, 55);

	printDict(D);

	insert(D, 43);

	printDict(D);

	delete(D, 33);
	printDict(D);
	printf("\nNumber %d %s in dictionary.", 43, (isMember(D, 43)) ? "is" : "is not");

	return 0;
}

void initDict(Dictionary A) {
	for (int i = 0; i < MAX; i++) {
		A[i] = EMPTY;
	}
}

int hash(int data) {
	return data % MAX;
}

void insert(Dictionary A, int data) {
	int index = hash(data);
	int stop = (index + MAX - 1) % MAX;
	int firstAvail = -1;

	int i;
	for (i = index; i != stop && A[i] != data && A[i] != EMPTY; i = (i + 1) % MAX) {
		if (firstAvail == -1 && A[i] == DELETED) {
			firstAvail = i;
		}
	}
	if (A[i] == EMPTY) {
		A[(firstAvail == -1) ? i : firstAvail] = data;
	}
}

void delete(Dictionary A, int data) {
	int index = hash(data);
	int stop = (index + MAX - 1) % MAX;

	int i;
	for (i = index; i != stop && A[i] != data && A[i] != EMPTY; i = (i + 1) % MAX);

	if (A[i] == data) {
		A[i] = DELETED;
	}
}

void printDict(Dictionary A) {
	printf("\n");
	for (int i = 0; i < MAX; i++) {
		printf("Index %d: ", i);
		if (A[i] == EMPTY) {
			printf("EMPTY");
		} else if (A[i] == DELETED) {
			printf("DELETED");
		} else {
			printf("%d", A[i]);
		}
		printf("\n");
	}
}

bool isMember(Dictionary A, int data) {
	int index = hash(data);
	int stop = (index + MAX - 1) % MAX;

	int i;
	for (i = index; i != stop && A[i] != data && A[i] != EMPTY; i = (i + 1) % MAX);

	return (A[i] == data) ? true : false;
}