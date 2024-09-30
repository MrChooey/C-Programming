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
bool inDict(Dictionary A, int data);
void printDict(Dictionary A);

int main(void) {
	Dictionary D;

	initDict(D);


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
	
}