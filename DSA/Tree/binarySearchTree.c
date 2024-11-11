#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
} *Tree;

void initTree(Tree *T);
void insertTree(Tree *T, int data);
void deleteTree(Tree *T, int data);
void deleteTreeWithChild(Tree *T);
bool isFound(Tree *T, int data);
void preOrder(Tree T);
void inOrder(Tree T);
void postOrder(Tree T);
int min(Tree T);
int max(Tree T);

int main(void) {
	Tree T = NULL;

	insertTree(&T, 5);
	insertTree(&T, 6);
	insertTree(&T, 7);
	insertTree(&T, 4);
	insertTree(&T, 3);
	insertTree(&T, 8);
	insertTree(&T, 9);
	insertTree(&T, 2);
	insertTree(&T, 1);

	printf("\nPreorder: ");
	preOrder(T);

	deleteTree(&T, 9);

	printf("\nDeleted 9 (Preorder): ");
	preOrder(T);

	printf("\nInorder: ");
	inOrder(T);

	printf("\nPostorder: ");
	postOrder(T);

	printf("\nMax = %d", max(T));
	printf("\nMin = %d", min(T));

	printf("\nNumber 8 %s found", (isFound(&T, 8)) ? "IS" : "IS NOT");

	return 0;
}

void initTree(Tree *T) {
	*T = NULL;
}

void insertTree(Tree *T, int data) {
	Tree temp = (Tree)malloc(sizeof(struct node));
	if (temp != NULL) {
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;

		Tree *trav;

		for (trav = T; *trav != NULL && (*trav)->data != data; trav = ((*trav)->data > data) ? 
			&(*trav)->left : &(*trav)->right);
		
		if (*trav == NULL) {
			*trav = temp;
		}
	}
}

void deleteTreeWithChild(Tree *T) {
	Tree temp = *T;
	*T = ((*T)->left != NULL) ? (*T)->left : (*T)->right;
	free(temp);
}

void deleteTree(Tree *T, int data) {
	Tree *trav;

	for (trav = T; *trav != NULL && (*trav)->data != data; trav = ((*trav)->data > data) ? 
		&(*trav)->left : &(*trav)->right);

	if (*trav != NULL) {
		if ((*trav)->left != NULL && (*trav)->right != NULL) {
			Tree *near = (*trav)->left;

			while ((*near)->right != NULL) {
				near = &(*near)->right;
			}

			(*trav)->data = (*near)->data;

			deleteTreeWithChild(near);
		} else {
			deleteTreeWithChild(trav);
		}
	}
}

bool isFound(Tree *T, int data) {
	if (T != NULL && (*T)->data != data) {
		T = ((*T)->data > data) ? (*T)->left : (*T)->right;
	}

	return (*T == NULL) ? false : true;
}

void preOrder(Tree T) {
	if (T != NULL) {
		printf("%d ", T->data);
		preOrder(T->left);
		preOrder(T->right);
	}
}

void inOrder(Tree T) {
	if (T != NULL) {
		inOrder(T->left);
		printf("%d ", T->data);
		inOrder(T->right);
	}
}

void postOrder(Tree T) {
	if (T != NULL) {
		postOrder(T->left);
		postOrder(T->right);
		printf("%d ", T->data);
	}
}

int min(Tree T) {
	return (T != NULL && T->left == NULL) ? T->data : min(T->left);
}

int max(Tree T) {
	return (T != NULL && T->right == NULL) ? T->data : max(T->right);
}
