#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
	int elements[MAX];
	int lastIndx;
} Tree;

void initTree(Tree *T);
void maxHeapify(Tree *T, int size, int parent);
void heapSort(Tree *T);
void insertTree(Tree *T, int data);

int main(void) {

	return 0;
}

void initTree(Tree *T) {
	T->lastIndx = 0;
}

void maxHeapify(Tree *T, int size, int parent) {
	int largest = parent;
	int left = parent * 2 + 1;
	int right = left + 1;

	if (left < size && T->elements[left] < T->elements[largest]) {
		largest = left;
	}
	if (right < size && T->elements[right] < T->elements[largest]) {
		largest = right;
	}

	if (largest != parent) {
		int temp = T->elements[largest];
		T->elements[largest] = T->elements[parent];
		T->elements[parent] = temp;

		maxHeapify(T, size, largest);
	}
}

void heapSort(Tree *T) {
	for (int i = (T->lastIndx - 1) / 2; i > 0; i--) {
		maxHeapify(T, T->lastIndx, i);
	}

	for (int i = T->lastIndx; i > 0; i--) {
		int temp = T->elements[0];
		T->elements[0] = T->elements[i];
		T->elements[i] = temp;

		maxHeapify(T, i, 0);
	}
}