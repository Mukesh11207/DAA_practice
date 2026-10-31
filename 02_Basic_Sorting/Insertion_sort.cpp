#include <bits/stdc++.h>
using namespace std;

void Insertion_sort(vector<int>& a,int n){
    for(int i = 1;i < n;i++){
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main(){
    vector<int> c = {1,43,23,67};
    Insertion_sort(c,c.size());
    for(int i = 0;i < c.size();i++){
        cout << c[i] << " ";
    }
    return 0;
}