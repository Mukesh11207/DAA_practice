#include <bits/stdc++.h>
using namespace std;

void lcs(string X,string Y){
    int m = X.length();
    int n = X.length();

    int dp[m + 1][n + 1];

    for(int i = 0;i <= m;i++){
        for(int j = 0;j <= n;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(X[i - 1] == Y[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    cout << "Length of LCS :- " << dp[m][n] << endl;

    int i = m;
    int j = n;

    string result = "";

    while(i > 0 && j > 0){
        if(X[i - 1] == Y[j - 1]){
            result += X[i - 1];
            i--;
            j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]){
            i--;
        }else{
            j--;
        }
    }
    reverse(result.begin(),result.end());

    cout << "LCS :- " << result << endl;
}

int main(){
    string X,Y;

    cout << "Enter first string :- ";
    cin >> X;

    cout << "Enter second string :- ";
    cin >> Y;

    lcs(X,Y);
    return 0;
}