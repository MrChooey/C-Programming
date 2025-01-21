#include <stdio.h>
#include <stdlib.h>

#define MAX 5
#define INF 999

typedef int Set[MAX];
typedef int AdjMatrix[MAX][MAX];

typedef struct {
	int nodes[MAX];
	int front;
	int rear;
} Queue;

typedef struct {
	int u, v;
	int weight;
} EdgeType;

typedef struct {
	EdgeType edges[MAX - 1];
	int nodeCount;
	int totalWeight;
} MinimumCostTree;

void bfs(AdjMatrix M, int root) {
	Set visited = {};
	visited[root] = 1;

	Queue Q;
	initQueue(&Q);

	enqueue(&Q, root);

	while (!isEmpty(Q)) {
		int node = dequeue(&Q);
		printf("%d ", node);

		for (int i = 0; i < MAX; i++) {
			if (visited[i] == 0 && M[node][i] != 0) {
				visited[i] = 1;
				enqueue(&Q, i);
			}
		}
	}
}