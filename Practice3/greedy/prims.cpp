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
void prims(int graph[V][V]){
    int key[V];
    int parent[V];
    bool mst[V];

    for(int i = 0;i < V;i++){
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }
    key[0] = 0;//important
    for(int count = 0;count < V - 1;count++){
        int u = findMin(key,mst);
        if(u == -1)
            break;
        mst[u] = true;
        
        for(int v = 0;v < V;v++){
            if(!mst[v] && graph[u][v] != 0 && key[v] > graph[u][v]){
                key[v] = graph[u][v];
                parent[v] = u;//dont forget;
            }
        }
    }
    int total = 0;
    for(int i = 1;i < V;i++){//from 1
        if(parent[i] != -1){
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
        total += graph[i][parent[i]] ;}
    }
    cout << "Total weight :- " << total << endl;
}

int main(){
    int graph[V][V];

    cout << "Enter adjacency matrix:\n";

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
        }
    }

    prims(graph);

    return 0;
}