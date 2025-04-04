#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure for BFS
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

// BFS Algorithm
void BFS(int graph[MAX][MAX], int startVertex, int numVertices) {
    int visited[MAX] = {0};
    Queue q;
    initQueue(&q);

    printf("Breadth-First Search starting from vertex %d:\n", startVertex);
    visited[startVertex] = 1;
    enqueue(&q, startVertex);

    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        for (int i = 0; i < numVertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

int main() {
    int numVertices, startVertex;
    int graph[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    BFS(graph, startVertex, numVertices);

    return 0;
}