#include <bits/stdc++.h>
using namespace std;

void merge(int arr[],int low,int mid,int high){
    int i = low;
    int j = mid + 1;
    int k = 0;
    int temp[high - low + 1];

    while(i <= mid && j <= high){//less than and equal
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
        }else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i <= mid){
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j <= high){
        temp[k] = arr[j];
        j++;
        k++;
    }
    for(int i = low,k = 0;i <= high;i++,k++){//from low to high(inclusive)
        arr[i] = temp[k];
    }
}

void mergesort(int arr[],int low,int high){
    if(low < high){//if not while
        int mid = low + (high - low)/2;

        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);

        merge(arr,low,mid,high);
    }
}

int main(){
    int arr[5] = {1,367,3,-2,8};
    mergesort(arr,0,4);

    for(int i : arr){
        cout << i << " ";
    }
    return 0;
}