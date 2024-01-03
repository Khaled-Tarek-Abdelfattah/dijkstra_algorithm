#include <iostream>
using namespace std;
#include <limits.h>

// Number of vertices in the graph
#define V 13

int minDistance(int dist[], bool sptSet[])
{

    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}
void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t" << dist[i] << endl;
}
void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V]; 
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist);
}
int main()
{
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0,2,5,2,4 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0,3,4,1,5 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2,8,6,3,6 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0,3,3,6,1 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0,4,4,6,3 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0,2,1,7,7 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6,0,7,6,6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7,3,2,7,11 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0,4,8,6,7 },
                        { 0, 0, 4, 0, 7, 0, 1, 7, 1,0,9,2 , 3}, 
                        { 1, 2, 2, 0, 0, 6, 6, 12, 0,4,0,1,2 },
                        { 4, 5, 7, 2, 9, 0, 2, 0, 2,3,7,0,4 },
                        { 9, 1, 1, 2, 9, 14, 5, 4, 2,1,5,5,0 }, };

    dijkstra(graph, 0);

    return 0;
}