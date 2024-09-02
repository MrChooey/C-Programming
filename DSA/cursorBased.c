#include <stdio.h>

#define MAX 10

typedef struct {
	int data;
	int link;
} NodeType;

typedef struct {
	NodeType nodes[MAX];
	int avail;
} VirtualHeap;

typedef int List;

void initHeap(VirtualHeap *VH);
int allocSpace(VirtualHeap *VH);
void deallocSpace(VirtualHeap *VH, int x);
void insertLast(VirtualHeap *VH, List *L, int x);
void insertFirst(VirtualHeap *VH, List *L, int x);
void deleteLast(VirtualHeap *VH, List *L, int x);

int main(void) {
	VirtualHeap VH;
	List L = 0;

	initHeap(&VH);

	return 0;
}

void initHeap(VirtualHeap *VH) {
	VH->avail = 0;
	for (int i = -1; i < MAX - 1; i++) {
		VH->nodes[i + 1].link = i;
	}
}

int allocSpace(VirtualHeap *VH) {
	int temp = VH->avail;
	if (VH->avail != -1) {
		VH->avail = VH->nodes[temp].link;
	}
	return temp;
}

void deallocSpace(VirtualHeap *VH, int x) {
	if (x > 0 && x < MAX) {
		VH->nodes[x].link = VH->avail;
		VH->avail = x;
	}
}

void insertFirst(VirtualHeap *VH, List *L, int x) {
	int temp = allocSpace(VH);

	if (temp != -1) {
		VH->nodes[temp].link = *L;
		VH->nodes[temp].data = x;
		*L = temp;
	}
}

void insertLast(VirtualHeap *VH, List *L, int x) {
	int temp = allocSpace(VH);

	VH->nodes[temp].link = -1;
	VH->nodes[temp].data = x;

	int i;

	for (i = *L; VH->nodes[i].link != -1; i = VH->nodes[i].link);
	
	VH->nodes[i].link = temp;
}

void deleteLast(VirtualHeap *VH, List *L, int x) {
	int i;

	for (i = *L; VH->nodes[i].link != -1; i = VH->nodes[i].link) {
		int next = VH->nodes[i].link;
		if (VH->nodes[next].link = -1) {
			VH->nodes[i].link = -1;
		}
	}

	deallocSpace(VH, i);
}