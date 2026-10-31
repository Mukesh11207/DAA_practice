#include <bits/stdc++.h>
using namespace std;

void Selection_sort(vector<int>&a,int n){
    for(int i = 0;i < n - 1;i++){
        int min = i;
        for(int j = i + 1;j < n;j++){
            if(a[min] > a[j]){
                min = j;
            }
        }
        swap(a[i],a[min]);
    }
}
int main(){
    vector<int> b = {1,4,5,2,8};
    Selection_sort(b,b.size());
    for(int i = 0;i < b.size();i++){
        cout << b[i] << " ";
    }
    return 0;
}