// Aim: To implement Dijkstra's algorithm and analyze its time complexity. 

#include <stdio.h> 
#include <limits.h> 
 
#define V 5 
 
int main() { 
    int g[V][V] = { 
        {0, 10, 0, 5, 0}, 
        {10, 0, 1, 2, 0}, 
        {0, 1, 0, 0, 4}, 
        {5, 2, 0, 0, 2}, 
        {0, 0, 4, 2, 0}}; 
    int d[V]; 
    int visited[V] = {0}; 
 
    /* Initialize distances */ 
    for (int i = 0; i < V; i++) 
        d[i] = INT_MAX; 
 
    /* Source vertex */ 
    d[0] = 0; 
 
    /* Dijkstra's Algorithm */ 
    for (int i = 0; i < V - 1; i++) { 
        int u = -1; 
 
        /* Find the unvisited vertex with minimum distance */ 
        for (int j = 0; j < V; j++) { 
            if (!visited[j] && (u == -1 || d[j] < d[u])) 
                u = j; 
        } 
 
        visited[u] = 1; 
 
        /* Update distances */ 
        for (int v = 0; v < V; v++) { 
            if (g[u][v] && d[u] != INT_MAX && 
                d[u] + g[u][v] < d[v]) { 
 
                d[v] = d[u] + g[u][v]; 
            } 
        } 
    } 
 
    printf("Shortest distances from source 0:\n"); 
 
    for (int i = 0; i < V; i++) 
        printf("0 -> %d = %d\n", i, d[i]); 
 
    return 0; 
}
