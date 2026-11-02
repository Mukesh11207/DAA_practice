#include <bits/stdc++.h>
using namespace std;

#define V 5
#define INF 99999

void floyd_warshall(int graph[V][V]){
    int dist[V][V];

    for(int i = 0;i < V;i++){
        for(int j = 0;j < V;j++){
            if(i == j){
                dist[i][j] = 0;
            }
            else if(graph[i][j] == 0){
                dist[i][j] = INF;
            }else{
                dist[i][j] = graph[i][j];
            }
        }
    }

    for(int k = 0;k < V;k++){
        for(int i = 0;i < V;i++){
            for(int j = 0;j < V;j++){
                if(dist[i][k] != INF && dist[k][j] != INF){
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    cout << "Shortes path matrix :- ";
    for(int i = 0;i < V;i++){
        for(int j = 0;j < V;j++){
            if(dist[i][j] == INF){
                cout << "INF ";
            }
            else{
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}
int main(){
    int graph[V][V];

    for(int i = 0;i < V;i++){
        for(int j = 0;j < V;j++){
            cin >> graph[i][j];
        }
    }
    floyd_warshall(graph);

    return 0;
}