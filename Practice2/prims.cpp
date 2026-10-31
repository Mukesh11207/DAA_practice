#include <bits/stdc++.h>
using namespace std;

#define V 5

int findMin(int key[],bool mst[]){
    int min = INT_MAX;
    int index = -1;

    for(int i = 0;i < V;i++){
        if(!mst[i] && key[i] < min){
            min = key[i];
            index = i;
        }
    }
    return index;
}

void prim(int graph[V][V]){
    int key[V];
    int parent[V];
    bool mst[V];

    for(int i = 0;i < V;i++){
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }
    key[0] = 0;

    for(int count = 0; count < V - 1;count++){
        int u = findMin(key,mst);

        mst[u] = true;

        for(int v = 0;v < V;v++){
            if(graph[u][v] != 0 && !mst[v] && graph[u][v] < key[v]){
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    int total = 0;

    cout << "\nEdges in MST:\n";

    for(int i = 1;i < V;i++){
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] 
        << endl;

        total += graph[i][parent[i]];
    }

    cout << "Total weight :- " << total << endl;
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

    prim(graph);

    return 0;
}