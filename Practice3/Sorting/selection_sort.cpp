#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[],int n){
    for(int i = 0;i < n - 1;i++){
        int minIdx = i;
        for(int j = i + 1;j < n;j++){
            if(arr[minIdx] > arr[j]){
                minIdx = j;
            }
        }
        swap(arr[i],arr[minIdx]);
    }
}

int main(){
    int arr[5] = {1,43,6,-1,5};
    selection_sort(arr,5);
    for(int i : arr){
        cout << i << " ";
    }
    return 0;
}