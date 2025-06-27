#include <stdio.h>
#define MAX 100
#define INF 9999

void dijkstra(int graph[MAX][MAX], int n, int start) {
    int distance[MAX], visited[MAX];

    // Initialize distances
    for (int i = 0; i < n; i++) {
        distance[i] = INF;
        visited[i] = 0;
    }

    distance[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int min = INF, u;

        // Find unvisited vertex with smallest distance
        for (int i = 0; i < n; i++) {
            if (!visited[i] && distance[i] <= min) {
                min = distance[i];
                u = i;
            }
        }

        visited[u] = 1;

        // Update distances of neighbors of u
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && distance[u] != INF &&
                distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    // Print the shortest distances
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, distance[i]);
    }
}

int main() {
    int graph[MAX][MAX], n, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    dijkstra(graph, n, start);

    return 0;
}

