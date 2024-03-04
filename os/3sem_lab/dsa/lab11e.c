/*Design, Develop and Implement a Program in C for the following operations on Graph(G) of Cities
a. Create a Graph of N cities using Adjacency Matrix.
b. Print all the nodes reachable from a given starting node in a digraph using BFS method
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

int adj[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE];
int queue[MAX_SIZE];
int front = -1, rear = -1;

void BFS(int v, int n) {
    visited[v] = 1;
    rear = front = -1;
    queue[++rear] = v;

    while (front != rear) {
        int cur = queue[++front];
        for (int i = 1; i <= n; i++) {
            if (adj[cur][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
                printf("%d -> %d\n", cur, i);
            }
        }
    }
}

void DFS(int v, int n) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 1; i <= n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            DFS(i, n);
        }
    }
}

int main() {
    int n, ch, start;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    do {
        printf("\n1. Reachable vertices using BFS\n2. Reachable vertices using DFS\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        printf("Enter the starting vertex: ");
        scanf("%d", &start);

        for (int i = 1; i <= n; i++) {
            visited[i] = 0;
        }

        switch (ch) {
            case 1: printf("Nodes reachable from starting vertex %d are:\n", start); BFS(start, n); break;
            case 2: printf("Nodes reachable from starting vertex %d are:\n", start); DFS(start, n); break;
            case 3: exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (1);

    return 0;
}
