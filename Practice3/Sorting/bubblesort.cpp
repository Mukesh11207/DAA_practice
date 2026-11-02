#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[],int n){
    for(int i = 0;i < n - 1;i++){
        for(int j = 0;j < n - i - 1;j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j],arr[j + 1]);
            }
        }
    }
}

int main(){
    int arr[5] = {23,8,-67,890,212};
    bubble_sort(arr,5);
    for(int i : arr){
        cout << i << " ";
    }
    return 0;
}