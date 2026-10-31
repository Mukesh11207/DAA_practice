//travelling salesman problem using DP

#include <bits/stdc++.h>
using namespace std;

#define INF 99999

int dp[1 << 20][20];

int tsp(int cost[20][20],int mask,int pos,int n){
    if(mask == (1 << n) - 1){
        return cost[pos][0];//all cities visited go back to first city
    }
    if(dp[mask][pos] != -1)
        return dp[mask][pos];//this is memoization

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

int main(){
    int n;

    cout << "Enter number of cities :- ";
    cin >> n;

    int cost[20][20];

    cout << "Enter cost of matrix:\n";

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> cost[i][j];
        }
    }

    memset(dp,-1,sizeof(dp));

    int answer = tsp(cost,1,0,n);

    cout << "Minimum tour cost :- " << answer << endl;

    return 0;
}