#include <bits/stdc++.h>
using namespace std;

vector<int> max_min(vector<int> a,int i,int j){
    vector<int> res;
    int max0,min0;

    if(i == j){
        max0 = min0 = a[i];
    }
    else if(i == j - 1){
        max0 = max(a[i],a[j]);
        min0 = max(a[i],a[j]);
    }
    else{
        int mid = i + (j - i)/2;
        int max1,min1,max2,min2;

        vector<int> left = max_min(a,i,mid);
        vector<int> right = max_min(a,mid+1,j);

        max1 = left.front();
        min1 = left.back();

        max2 = right.front();
        min2 = right.back();

        max0 = max(max1,max2);
        min0 = min(min1,min2);
    }
    res.push_back(max0);
    res.push_back(min0);

    return res;
}
int main(){
    vector<int> a = {3,54,1,-2,767};

    vector<int> b = max_min(a,0,a.size() - 1);

    cout << "Max :- " << b.front() << endl;
    cout << "Min :- " << b.back() << endl;

    return 0;
}