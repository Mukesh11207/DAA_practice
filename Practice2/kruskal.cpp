#include <bits/stdc++.h>
using namespace std;

#define V 5

struct Edge{
    int u;
    int v;
    int weight;
};

bool compare(Edge a,Edge b){
    return a.weight < b.weight;
}

int findParent(int parent[],int x){
    if(parent[x] = x){
        return x;
    }
    return parent[x] = findParent(parent,parent[x]);
}

void unionSets(int parent[],int rank[],int u,int v){
    u = findParent(parent,u);
    v = findParent(parent,v);

    if(u != v){
        if(rank[u] < rank[v])
            parent[u] = v;
        else if(rank[u] > rank[v])
            parent[v] = u;
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
}

void kruskal(int graph[V][V]){
    vector<Edge> edges;

    for(int i = 0;i < V;i++){
        for(int j = i + 1;j < V;j++){
            if(graph[i][j] != 0){
                edges.push_back({i,j,graph[i][j]});
            }
        }
    }
    sort(edges.begin(),edges.end(),compare);

    int parent[V];
    int rank[V];

    for(int i = 0;i < V;i++){
        parent[i] = i;
        rank[i] = 0;
    }

    int count = 0;
    int total = 0;

    cout << "\nEdges in MST:\n";

    for(auto edge : edges){
        int pu = findParent(parent,edge.u);
        int pv = findParent(parent,edge.v);

        if(pu != pv){
            cout << edge.u << " - " << edge.v << " : " <<
            edge.weight << endl;

            total += edge.weight;

            unionSets(parent,rank,edge.u,edge.v);
            count++;

            if(count == V - 1)
                break;
        }
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

    kruskal(graph);

    return 0;
}