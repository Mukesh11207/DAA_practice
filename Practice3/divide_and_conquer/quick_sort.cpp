#include <bits/stdc++.h>
using namespace std;

int partition(int arr[],int low,int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low;j < high;j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i + 1],arr[high]);
    return i + 1;
}

void quick_sort(int arr[],int low,int high){
    if(low < high){//if is used not while
        int pi = partition(arr,low,high);

        quick_sort(arr,low,pi - 1);
        quick_sort(arr,pi + 1,high);
    }
}

int main(){
    int arr[5] = {1,45,0,4,999};
    quick_sort(arr,0,4);
    for(int x : arr){
        cout << x << " ";
    }
    return 0;
}