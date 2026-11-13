#include <bits/stdc++.h>
using namespace std;

#define MAX 20
#define INF 99999

int dp[1 << MAX][MAX];
int tsp(int cost[MAX][MAX],int mask,int pos,int n){
    if(mask == (1 << n) - 1){
        return cost[pos][0];
    }
    if(dp[mask][pos] != -1){
        return dp[mask][pos];
    }
    int ans = INF;
    for(int city = 0;city < n;city++){
        if((mask & (1 << city)) == 0){
            int newCost = cost[pos][city] +
                tsp(cost,mask | (1 << city),city,n);
        ans = min(ans,newCost);
        }
    }
    return dp[mask][pos] = ans;
}
void PrintRoute(int cost[MAX][MAX],int mask,int pos,int n){
    cout << pos << " ";

    if(mask == (1 << n) - 1){
        cout << "0";
        return;
    }

    for(int city = 0;city < n;city++){
        if((mask & (1 << city)) == 0){
            int newCost = cost[pos][city] + 
                tsp(cost,mask | (1 << city),city,n);
            if(newCost == dp[mask][pos]){
                PrintRoute(cost,mask | 1 << city,city,n);
                return;
            }
        }
    }
}