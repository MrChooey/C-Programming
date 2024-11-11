#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
	int elements[MAX];
	int lastIndx;
} Tree;

void initTree(Tree *T);
void insertTree(Tree *T, int data);
void deleteMin(Tree *T);
void maxHeapify(Tree *T, int size, int parent);
void heapSort(Tree *T, int size);

int main(void) {
	

	return 0;
}

void initTree(Tree *T) {
	T->lastIndx = -1;
}

void insertTree(Tree *T, int data) {
	if (T->lastIndx + 1 < MAX) {
		int child = ++(T->lastIndx);
		int parent = (child - 1) / 2;

		while (child > 0 && T->elements[child] > data) {
			T->elements[child] = T->elements[parent];

			child = parent;
			parent = (parent - 1) / 2;
		}

		T->elements[child] = data;
	}
}

void deleteMin(Tree *T) {
	int temp = -1;
	if (T->lastIndx >= 0) {
		temp = 
	}
}

void maxHeapify(Tree *T, int size, int parent) {
	int largest = parent;
	int left = parent * 2 + 1;
	int right = left + 1;

	if (left < size && T->elements[left] > T->elements[largest]) {
		largest = left;
	}
	if (right < size && T->elements[right] > T->elements[largest]) {
		largest = right;
	}

	if (largest != parent) {
		int temp = T->elements[largest];
		T->elements[largest] = T->elements[parent];
		T->elements[parent] = temp;

		maxHeapify(T, size, largest);
	}
}

void heapSort(Tree *T, int size) {
	for (int i = (size - 1) / 2; i >= 0; i--) {
		maxHeapify(T, size, i);
	}

	for (int i = T->lastIndx; i > -1; i--) {
		int temp = T->elements[i];
		T->elements[i] = T->elements[0];
		T->elements[0] = temp;

		maxHeapify(T, i, 0);
	}
}