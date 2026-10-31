#include <bits/stdc++.h>
using namespace std;

long long karatsuba(long long x,long long y){
    if(x < 10 || y < 10){
        return x * y;
    }

    int n = max(to_string(x).length(),
                to_string(y).length());
    int m = n / 2;

    long long power = pow(10,m);

    long long x1 = x / power;
    long long x2 = x % power;

    long long y1 = y / power;
    long long y2 = y % power;

    long long z2 = karatsuba(x1,y1);
    long long z0 = karatsuba(x2,y2);
    long long z1 = karatsuba(x1 + x2,y1 + y2) - z2 - z0;

    return z2 * power * power + z1 * power + z0;
}

int main(){
    long long x,y;

    cout << "Enter first number :- ";
    cin >> x;

    cout << "Enter second number :- ";
    cin >> y;

    cout << "Product :- " << karatsuba(x,y) << endl;

    return 0;
}