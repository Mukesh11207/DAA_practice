#include<iostream>
#include <vector>
using namespace std;

int linear_search(const vector<int>&a,int b){
    for(int i = 0;i < a.size();i++){
        if(a.at(i) == b){
            return i;
        }
    }
    return -1;
}
int main(){
    int size;
    cout << "Enter size of array :- ";
    cin >> size;
    
    vector<int> a(size);
    cout << "Enter array elements :- \n";
    for(int i = 0;i < size;i++){
        cin >> a[i];
    }
    int target;
    cout << "Enter target element :- ";
    cin >> target;
    int y = linear_search(a,target);
    if(y >= 0){
        cout << "Element found at position :- " << y + 1 << endl;
    }
    else{
        cout << "Element not found";
    }
    return 0;
}