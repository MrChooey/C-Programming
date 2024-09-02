#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
} *List;

typedef struct {
	List front;
	List rear;
} Queue;

void initQueue(Queue *Q);
void enqueue(int x, Queue *Q);
void dequeue(Queue *Q);
void printThis(Queue Q);

int main(void) {
	Queue Q;

	initQueue(&Q);

	enqueue(1, &Q);
	enqueue(2, &Q);
	enqueue(3, &Q);

	printThis(Q);

	dequeue(&Q);

	printThis(Q);

	return 0;
}

void initQueue(Queue *Q) {
	Q->front = NULL;
	Q->rear = NULL;
}

void enqueue(int x, Queue *Q) {
	List temp = (List)malloc(sizeof(struct node));
	if (temp != NULL) {
		temp->data = x;
		temp->next = NULL;
		if (Q->front == NULL) {
			Q->front = temp;
		} else {
			Q->rear->next = temp;
		}
		Q->rear = temp;
	}
}

void dequeue(Queue *Q) {
	if (Q->front != NULL) {	
		List temp;
		temp = Q->front;
		Q->front = temp->next;

		free(temp);

		if (Q->front == NULL) {
			Q->rear = NULL;
		}
	}
}

void printThis(Queue Q) {
	while (Q.front != NULL) {
		printf(" %d", Q.front->data);
		Q.front = Q.front->next;
	}
	printf("\n");
}
