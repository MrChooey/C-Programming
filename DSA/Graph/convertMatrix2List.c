#include <stdio.h>

#define MAX 11
#define INF INT_MAX

typedef char vertex;

typedef struct {
    int matrix[MAX][MAX];
    int edgeCount;
} labeledAdjMatrix;

typedef struct {
    vertex tail;
    vertex head;
    int weight;
} edge;

typedef struct {
    vertex adjVertex;
    int weight;
} adjType;

typedef struct node {
    adjType data;
    struct node *next;
} *adjList;

typedef struct {
    adjList head[MAX];
    int edgeCount;
} directedAdjList;

void initMatrix(labeledAdjMatrix *M) {
    M->edgeCount = 0;
    int i,j;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            M->matrix[i][j] = 0;
        }
    }
}

void populateMatrix(labeledAdjMatrix *M) {
    edge data[MAX] = {
        {'A', 'B', 10},
        {'A', 'H', 20},
        {'B', 'F', 20},
        {'C', 'A', 15},
        {'D', 'H', 30},
        {'D', 'E', 20},
        {'E', 'B', 20},
        {'E', 'H', 20},
        {'F', 'C', 15},
        {'G', 'F', 5},
        {'G', 'A', 10},
    };
    
    int i;
    for (i = 0; i < M->edgeCount; i++) {
        M->matrix[data[i].tail - 'A'][data[i].head - 'A'] = data[i].weight;
        M->edgeCount++;
    }
}

void displayMatrix(labeledAdjMatrix M) {
    int i,j;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            if (M.matrix[i][j] > 0) {
                printf("Weight from %c to %c is %d\n", i + 'A', j + 'A', M.matrix[i][j]);
            }
        }
    }
}

int main(void) {
    labeledAdjMatrix matrix;
    
    initMatrix(&matrix);
    populateMatrix(&matrix);
    
    displayMatrix(matrix);
    
    return 0;
}







