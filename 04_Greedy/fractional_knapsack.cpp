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

    Item items[n];
    cout << "Enter weights and profit of items :- ";
    for(int i = 0;i < n;i++){
        cin >> items[i].weight >> items[i].profit;
        items[i].ratio = (double)items[i].profit/items[i].weight;
    }
    int capacity;
    cout << "Enter knapsack capacity :- ";
    cin >> capacity;

    double maxProfit = 0;
    for(int i = 0;i < n;i++){
        if(capacity == 0){
            break;
        }
        if(items[i].weight <= capacity){
            capacity -= items[i].weight;
            maxProfit += items[i].profit;
        }
        else{
            double fraction = (double)capacity/items[i].weight;
            maxProfit += fraction * items[i].profit;
            capacity = 0;
        }
    }
    cout << "Maximum Profit :- " << maxProfit;
    return 0;
}