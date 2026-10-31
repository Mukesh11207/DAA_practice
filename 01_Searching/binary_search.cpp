#include <bits/stdc++.h>
using namespace std;

void _sort(vector<int> &a,int n){
    for(int i = 0;i < n;i++){
        for(int j = i;j < n;j++){
            if(a[i] > a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
int binary_search(const vector<int>&a,int low,int high,int target){
    while(low <= high){
        int mid = low + (high - low)/2;
        if(a[mid] == target){
            return mid;
        }
        else if(a[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int n;
    cout << "Enter size :- ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter array elements :- ";
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    int target;
    cout << "Enter target element :- ";
    cin >> target;
    _sort(a,n);
    int y = binary_search(a,0,n - 1,target);
    if(y >= 0){
        cout << "Element found at :- " << y;
    }
    else{
        cout << "Element not found";
    }
    return 0;
}