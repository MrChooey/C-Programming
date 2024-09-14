#include <stdio.h>
#include <stdbool.h>

#define MAX 8

typedef struct {
	int arr[MAX];
	int top;
} Stack;

void initStack(Stack *L); //
void push(Stack *L, int x); //
void pop(Stack *L); //
bool isEmpty(Stack L);  //
bool isFull(Stack L); //
void print(Stack *L); //
void insertBottom(Stack *L, int x);

int main(void) {
	Stack L;

	initStack(&L);

	push(&L, 1);
	push(&L, 2);
	push(&L, 3);
	push(&L, 4);

	print(&L);

	pop(&L);

	print(&L);

	insertBottom(&L, 9);

	print(&L);

	return 0;
}

void initStack(Stack *L) {
	L->top = 0;
}

void push(Stack *L, int x) {
	if (L->top < MAX) {
		L->arr[L->top] = x;
		L->top++;
	}
}

void pop(Stack *L) {
	if (L->top != 0) L->top--;
}

bool isEmpty(Stack L) {
	return (L.top == 0) ? 1 : 0;
}

bool isFull(Stack L) {
	return (L.top == MAX) ? 1 : 0;
}

void print(Stack *L) {
	for (int i = 0; i < L->top; i++) {
		printf("%d ", L->arr[i]);
	}
	printf("\n");
}

void insertBottom(Stack *L, int x) {
	if (isEmpty(*L)) {
		push(L, x);
	} 
	else if (!(isFull(*L))) {
		Stack A;

		initStack(&A);

		while (!(isEmpty(*L))) {
			push(&A, L->arr[L->top - 1]);
			pop(L);
		}

		push(L, x);

		while (!(isEmpty(A))) {
			push(L, A.arr[A.top - 1]);
			pop(&A);
		}
	}
}