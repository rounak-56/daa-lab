// Aim: To implement Bellman-Ford algorithm and analyse its time complexity.

#include <stdio.h>
#include <limits.h>

#define V 5
#define E 8

struct Edge {
    int src, dest, weight;
};

void bellmanFord(struct Edge edges[], int source) {
    int dist[V];

    // Initialize distances
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    // Relax all edges V - 1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if (dist[u] != INT_MAX &&
                dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for a negative-weight cycle
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;

        if (dist[u] != INT_MAX &&
            dist[u] + w < dist[v]) {
            printf("Graph contains a negative-weight cycle.\n");
            return;
        }
    }

    // Print shortest distances
    printf("Vertex\tDistance from Source\n");

    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            printf("%d\tINF\n", i);
        } else {
            printf("%d\t%d\n", i, dist[i]);
        }
    }
}

int main(void) {
    struct Edge edges[E] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    printf("----- Bellman-Ford Algorithm -----\n");

    bellmanFord(edges, 0);

    return 0;
}
