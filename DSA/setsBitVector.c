#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef int Set[MAX];

void initSet(Set A);
void insert(Set A, int x);
void delete(Set A, int x);
void printSet(Set A);
Set *unionSet(Set A, Set B);
Set *intersection(Set A, Set B);
Set *difference(Set A, Set B);

int main(void) {
	Set A;

	initSet(A);

	insert(A, 0);
	insert(A, 1);
	insert(A, 2);
	insert(A, 3);
	insert(A, 4);
	insert(A, 5);

	printf("Elements of Set A: ");
	printSet(A);

	Set B;

	initSet(B);

	insert(B, 2);
	insert(B, 3);
	insert(B, 4);
	insert(B, 5);
	insert(B, 6);
	insert(B, 7);

	printf("Elements of Set B: ");
	printSet(B);

	Set *U = unionSet(A, B);

	printf("Elements of (A V B): ");
	printSet(*U);

	Set *I = intersection(A, B);

	printf("Elements of (A ^ B): ");
	printSet(*I);

	Set *D = difference(A, B);

	printf("Elements of (A - B): ");
	printSet(*D);

	return 0;
}

void initSet(Set A) {
	for (int i = 0; i < MAX; i++) {
		A[i] = 0;
	}
}

void insert(Set A, int x) {
	int i;
	for (i = 0; i < MAX && i != x; i++);
	if (i != MAX) {
		A[i] = 1;
	}
}

void delete(Set A, int x) {
	int i;
	for (i = 0; i < MAX && i != x; i++);
	if (i != MAX) {
		A[i] = 0;
	}
}

void printSet(Set A) {
	printf("{ ");
	for (int i = 0; i < MAX; i++) {
		if (A[i] == 1) printf("%d ", i);
	}
	printf("}\n");
}

Set *unionSet(Set A, Set B) {
	Set *U = malloc(sizeof(Set));

	initSet(*U);

	int i;
	for (i = 0; i < MAX; i++) {
		(*U)[i] = (A[i] | B[i]);
	}

	return U;
}

Set *intersection(Set A, Set B) {
	Set *I = (Set*)malloc(sizeof(Set));
	
	int i;
	for (i = 0; i < MAX; i++) {
		(*I)[i] = (A[i] & B[i]);
	}

	return I;
}

Set *difference(Set A, Set B) {
	Set *D = (Set*)malloc(sizeof(Set));

	int i;
	for (i = 0; i < MAX; i++) {
		(*D)[i] = (A[i] & ~B[i]);
	}

	return D;
}
