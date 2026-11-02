#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[],int n){
    for(int i = 1;i < n;i++){
        int key = arr[i];//initialise key
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;//j--
        }
        arr[j + 1] = key;//not swap initialise j + 1 to key
    }
}
int main(){
    int arr[5] = {12,4,-3,54,67};
    insertion_sort(arr,5);
    for(int i : arr){
        cout << i << " ";
    }
    return 0;
}