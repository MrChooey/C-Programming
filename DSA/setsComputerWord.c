#include <stdio.h>

#define MAX (sizeof(unsigned int) * 8)

typedef unsigned int Set;

void initSet(Set *A);
void insert(Set *A, int x);
void delete(Set *A, int x);
void displayBitPattern(Set A);
void displayElems(Set A);
Set unionSet(Set A, Set B);
Set intersection(Set A, Set B);
Set difference(Set A, Set B);

int main(void) {
	Set A;

	initSet(&A);

	insert(&A, 0);
	insert(&A, 1);
	insert(&A, 2);
	insert(&A, 3);
	insert(&A, 14);
	insert(&A, 15);
	insert(&A, 16);
	insert(&A, 17);
	insert(&A, 23);
	insert(&A, 31);

	printf("Elements of Set A: { ");
	displayElems(A);
	printf("}\n");

	printf("Set A Bit Pattern: ");
	displayBitPattern(A);

	Set B;

	initSet(&B);

	insert(&B, 1);
	insert(&B, 2);
	insert(&B, 3);
	insert(&B, 4);
	insert(&B, 5);
	insert(&B, 15);
	insert(&B, 16);
	insert(&B, 17);
	insert(&B, 18);
	insert(&B, 22);
	insert(&B, 24);
	insert(&B, 30);

	printf("Elements of Set B: { ");
	displayElems(B);
	printf("}\n");

	printf("Set B Bit Pattern: ");
	displayBitPattern(B);

	Set U = unionSet(A, B);
	printf("Union Set Bit Pattern: ");
	displayBitPattern(U);

	Set I = intersection(A, B);
	printf("Intersection Set Bit Pattern: ");
	displayBitPattern(I);

	Set D = difference(A, B);
	printf("Difference Set Bit Pattern: ");
	displayBitPattern(D);

	return 0;
}

void initSet(Set *A) {
	*A = 0;
}

void insert(Set *A, int x) {
	*A |= (1 << x);
}

void delete(Set *A, int x) {
	*A &= ~(1 << x);
}

void displayBitPattern(Set A) {
	Set mask = 1 << (MAX - 1);
	for (; mask != 0; mask >>= 1) {
		printf("%d ", (A & mask) ? 1 : 0);
	}
	printf("\n\n");
}

void displayElems(Set A) {
	Set mask = 1;
	Set stop = 1 << (MAX - 1);
	for (int i = 0; mask != stop; mask <<= 1, i++) {
		if ((A & mask) > 0) {
			printf("%d ", i);
		}
	}
}

Set unionSet(Set A, Set B) {
	return (A | B);
}

Set intersection(Set A, Set B) {
	return (A & B);
}

Set difference(Set A, Set B) {
	return (A & ~B);
}
