#include <bits/stdc++.h>
using namespace std;

#define V 5
#define INF 99999

int findMin(int dist[],bool visited[]){
    int min = INF;
    int index = -1;

    for(int i = 0;i < V;i++){
        if(!visited[i] && dist[i] < min){
            min = dist[i];
            index = i;
        }
    }
    return index;
}
void dijkstra(int graph[V][V],int source){
    int dist[V];
    bool visited[V];

    for(int i = 0;i < V;i++){
        dist[i] = INF;
        visited[i] = false;
    }

    dist[source] = 0;

    for(int count = 0;count < V - 1;count++){
        int u = findMin(dist,visited);

        visited[u] = true;

        for(int v = 0;v < V;v++){
            if(graph[u][v] != 0 && !visited[v] &&
            dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            } 
        }
    }
    cout << "\nShortest distances from source " << source << ":\n";

    for(int i = 0; i < V; i++)
    {
        cout << source << " -> " << i
             << " = " << dist[i] << endl;
    }
}
int main()
{
    int graph[V][V];

    cout << "Enter adjacency matrix:\n";

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
        }
    }

    int source;

    cout << "Enter source vertex: ";
    cin >> source;

    dijkstra(graph, source);

    return 0;
}