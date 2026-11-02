#include <bits/stdc++.h>
using namespace std;

long long karatsuba(long long X,long long Y){
    if(X < 10 || Y < 10){//base case
        return X * Y;
    }
    int n = max(to_string(X).size(),to_string(Y).size());
    int m = n / 2;

    long long power = pow(10,m);

    long long a = X / power;
    long long b = X % power;

    long long c = Y / power;
    long long d = Y % power;

    long long z2 = karatsuba(a,c);
    long long z0 = karatsuba(b,d);
    long long z1 = karatsuba(a + b,c + d) - z2 - z0;

    return z2 * power * power + z1 * power + z0;
}

int main(){
    int x,y;
    cout << "Enter 2 numbers :- ";
    cin >> x >> y;

    cout << karatsuba(x,y) << endl;
    return 0;
}