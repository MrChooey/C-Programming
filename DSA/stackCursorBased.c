#include <stdio.h>

#define MAX 20

typedef struct {
	int data;
	int next;
} NodeType;

typedef struct {
	NodeType nodes[MAX];
	int avail;
} VirtualHeap;

typedef int List;

void initHeap(VirtualHeap *VH);
int allocSpace(VirtualHeap *VH);
void deallocSpace(VirtualHeap *VH, int x);
void push(VirtualHeap *VH, List *L, int x);
void pop(VirtualHeap *VH, List *L);
void print(VirtualHeap VH, List L);
void insertSorted(VirtualHeap *VH, List *L, int x);

int main(void) {
	VirtualHeap VH;
	List L = -1;

	initHeap(&VH);

	push(&VH, &L, 1);
	push(&VH, &L, 2);
	push(&VH, &L, 4);
	push(&VH, &L, 5);
	push(&VH, &L, 6);
	push(&VH, &L, 7);

	printf("Pushed Elements: ");
	print(VH, L);

	pop(&VH, &L);
	pop(&VH, &L);
	pop(&VH, &L);

	printf("\nPopped Elements: ");
	print(VH, L);

	insertSorted(&VH, &L, 3);

	printf("\nInsert Sorted Elements: ");
	print(VH, L);

	return 0;
}

void initHeap(VirtualHeap *VH) {
	VH->avail = MAX - 1;
	for (int i = -1; i < MAX - 1; i++) {
		VH->nodes[i + 1].next = i;
	}
}

int allocSpace(VirtualHeap *VH) {
	int temp = VH->avail;
	if (VH->avail != -1) {
		VH->avail = VH->nodes[temp].next;
	}
	return temp;
}

void deallocSpace(VirtualHeap *VH, int x) {
	if (x > 0 && x < MAX) {
		VH->nodes[x].next = VH->avail;
		VH->avail = x;
	}
}

void push(VirtualHeap *VH, List *L, int x) {
	int temp = allocSpace(VH);
	if (temp != -1) {
		VH->nodes[temp].data = x;
		VH->nodes[temp].next = *L;
		*L = temp;
	}
}

void pop(VirtualHeap *VH, List *L) {
	int temp = *L;
	*L = VH->nodes[temp].next;
	deallocSpace(VH, temp);
}

void print(VirtualHeap VH, List L) {
	int trav;
	for (trav = L; trav != -1; trav = VH.nodes[trav].next) {
		printf("%d ", VH.nodes[trav].data);
	}
}

void insertSorted(VirtualHeap *VH, List *L, int x) {
	List dummy = -1;

	while ((*L) != -1 && VH->nodes[(*L)].data > x) {
		push(VH, &dummy, VH->nodes[(*L)].data);
		pop(VH, L);
	}

	push(VH, L, x);

	while (dummy != -1) {
		push(VH, L, VH->nodes[dummy].data);
		pop(VH, &dummy);
	}
}