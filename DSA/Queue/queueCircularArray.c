#include <stdio.h>

#define MAX 8

typedef struct {
	int elem[MAX];
	int top;
	int rear;
} Queue;

void initQueue(Queue *Q);
void enqueue(int x, Queue *Q);
void dequeue(Queue *Q);
void print(Queue Q);

int main(void) {
	Queue Q;

	initQueue(&Q);
	
	enqueue(1, &Q);
	enqueue(2, &Q);
	enqueue(3, &Q);
	enqueue(4, &Q);
	enqueue(6, &Q);

	dequeue(&Q);

	print(Q);

	return 0;
}

void initQueue(Queue *Q) {
	// Empty Queue
	Q->top = 1;
	Q->rear = 0;
}

void enqueue(int x, Queue *Q) {
	if (Q->top != (Q->rear + 2) % MAX) {
		Q->rear = (Q->rear + 1) % MAX;
		Q->elem[Q->rear] = x;
	}
}

void dequeue(Queue *Q) {
	if (Q->top != (Q->rear + 1) % MAX) {
		Q->top = (Q->top + 1) % MAX;
	}
}

void print(Queue Q) {
	if (Q.top != (Q.rear + 1) % MAX) {
		while (Q.top != (Q.rear + 1) % MAX) {
			printf("%d ", Q.elem[Q.top]);
			Q.top = (Q.top + 1) % MAX;
		}
	}
}