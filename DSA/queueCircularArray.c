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

int main(void) {
	Queue Q;

	initQueue(&Q);
	
	enqueue(1, &Q);

	dequeue(&Q);

	return 0;
}

void initQueue(Queue *Q) {
	// Empty Queue
	Q->top = 1;
	Q->rear = 0;
}

void enqueue(int x, Queue *Q) {
	if(Q->top != (Q->rear + 2) % MAX) {
		Q->elem[(Q->rear + 1) % MAX] = x;
	}
}

void dequeue(Queue *Q) {
	if(Q->top != (Q->rear + 1) % MAX) {
		Q->top = (Q->top + 1) % MAX;
	}
}