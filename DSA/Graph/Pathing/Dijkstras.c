#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef int Set[MAX];
typedef int AdjMatrix[MAX][MAX];

int* dijkstras(AdjMatrix M, int root) {
	int* weightFromRoot = (int*)malloc(sizeof(int) * MAX);

	if (weightFromRoot != NULL) {
		Set visited = {};
		visited[root] = 1;

		// initialize weight from root
		for (int i = 0; i < MAX; i++) {
			weightFromRoot[i] = M[root][i];
		}

		weightFromRoot[root] = 0;

		// algorithm
		for (int i = 1; i < MAX; i++) {
			int smallestIndex = 0;

			// find smallest
			for (int j = 0; j < MAX; j++) {
				if (visited[smallestIndex] == 1 || (weightFromRoot[j] < weightFromRoot[smallestIndex] && visited[j] == 0)) {
					smallestIndex = j;
				}
			}

			// add smallestIndex to visited
			visited[smallestIndex] = 1;

			for (int k = 0; k < MAX; k++) {
				if (visited[k] == 0) {
					int nextWeight = weightFromRoot[smallestIndex] + M[smallestIndex][k];					// adds the new path from smallestIndex to next index
					weightFromRoot[k] = (weightFromRoot[k] < nextWeight) ? weightFromRoot[k] : nextWeight;	// new weight gets the lesser of the two
				}
			}
		}
	}

	return weightFromRoot;
}