#include <stdio.h>

#define MAX 100
#define INF 9999

typedef struct {
    int u, v, w;
} Edge;

int parent[MAX];

// Find root of a vertex
int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

// Union of two sets
int unionSet(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

// Sort edges by weight
void sortEdges(Edge edges[], int e) {
    Edge temp;
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, e;
    Edge edges[MAX];
    int total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter %d edges (u v weight):\n", e);
    for (int i = 0; i < e; i++) {
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    sortEdges(edges, e);

    printf("Edges in MST:\n");
    int count = 0;

    for (int i = 0; i < e && count < n - 1; i++) {
        int u_root = find(edges[i].u);
        int v_root = find(edges[i].v);

        if (unionSet(u_root, v_root)) {
            printf("%d - %d : %d\n", edges[i].u, edges[i].v, edges[i].w);
            total += edges[i].w;
            count++;
        }
    }

    printf("Total cost of MST: %d\n", total);

    return 0;
}

