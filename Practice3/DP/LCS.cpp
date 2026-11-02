#include <bits/stdc++.h>
using namespace std;

void LCS(string x,string y){
    int m = x.length();
    int n = y.length();

    int dp[m + 1][n + 1];

    for(int i = 0;i <= m;i++){
        for(int j = 0;j <= n;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(x[i - 1] == y[j - 1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j - 1]);
            }
        }
    }
    int length = dp[m][n];
    string result = "";
    int i = m;
    int j = n;

    while(i > 0 && j > 0){//only greater than 0
        if(x[i - 1] == y[j - 1]){
            result += x[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j - 1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(result.begin(),result.end());
    cout << "Length :- " << dp[m][n] << endl;
    cout << "string :- " << result << endl;
}

int main(){
    string a = "ABCDGH";
    string b = "AEDFHR";

    LCS(a,b);

    return 0;
}