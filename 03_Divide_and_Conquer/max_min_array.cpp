#include <bits/stdc++.h>
using namespace std;

vector<int> max_min(vector<int> a,int i,int j){
    vector<int> res;
    int _max,_min;
    if(i == j){
        _max = _min = a[i];
    }
    else if(i == j - 1){
        _max = max(a[i],a[j]);
        _min = min(a[i],a[j]);
    }
    else{
        int mid = i + (j - i)/2;
        int max1,max2,min1,min2;
        max1 = max_min(a,i,mid).front();
        min1 = max_min(a,i,mid).back();
        min2 = max_min(a,mid+1,j).back();
        max2 = max_min(a,mid+1,j).front();
        _max = max(max1,max2);
        _min = min(min1,min2);
    }
    res.push_back(_max);
    res.push_back(_min);
    return res;
}

int main(){
    vector<int> a = {1,4,2,56,67,-1,0};
    vector<int> b = max_min(a,0,a.size()-1);
    cout << "Max Element :- " << b.front() << endl;
    cout << "Min Element :- " << b.back();
    return 0;
}