#include <bits/stdc++.h>
using namespace std;

struct Item{
    int weight;
    int profit;
    double ratio;
};

bool compare(Item a,Item b){
    return a.ratio > b.ratio;
}

int main(){
    int n;
    cout << "Enter number of items :- ";
    cin >> n;

    vector<Item> items(n);
    cout << "Enter weight and profit :- ";
    for(int i = 0;i < n;i++){
        cin >> items[i].weight >> items[i].profit;

        items[i].ratio = (double)items[i].profit/items[i].weight;
    }
    sort(items.begin(),items.end(),compare);
    int capacity;
    cout << "Enter knapsack capacity :- ";
    cin >> capacity;
    double maxprofit = 0;
    for(int i = 0;i < n;i++){
        if(capacity == 0){
            break;
        }
        if(items[i].weight <= capacity){
            capacity -= items[i].weight;
            maxprofit += items[i].profit;
        }
        else{
            double fraction = (double)capacity/items[i].weight;
            capacity = 0;
            maxprofit += fraction * items[i].profit;
        }
    }
    cout << "Max profit :- " << maxprofit;
    return 0;
}