#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &a,int n){
    for(int i = 0;i < n - 1;i++){
        bool swapped = false;
        for(int j = 0;j < n - i - 1;j++){
            if(a[j] > a[j+1]){
                swap(a[j],a[j+1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
}

int main(){
    vector<int> a = {5,2,4,1,8};
    bubble_sort(a,a.size());
    for(int i = 0;i < a.size();i++){
        cout << a[i] << " ";
    }
    return 0;
}