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
int main(void) {


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

	return (T == NULL) ? false : true;
}



