#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef int Set[MAX];
typedef int AdjMatrix[MAX][MAX];

int **floyds(AdjMatrix M) {
	int **weights = (int**)malloc(sizeof(int) * MAX);

	if (weights != NULL) {
		for (int i = 0; i < MAX; i++) {
			weights[i] = (int*)malloc(sizeof(int) * MAX);

			for (int j = 0; j < MAX; j++) {
				if (i == j) {
					weights[i][j] = 0;
				} else {
					weights[i][j] = M[i][j];
				}
			}
		}

		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				for (int k = 0; k < MAX; k++) {
					int nextWeights = weights[i][k] + weights[k][j];
					weights[i][j] = (nextWeights < weights[i][j]) ? nextWeights : weights[i][j];
				}
			}
		}
	}

	return weights;
}