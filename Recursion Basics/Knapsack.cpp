#include<bits/stdc++.h>
using namespace std;

int knapsackHelper(int i, vector<int>& weights, vector<int>& values, int remainingWeight) {
    if(remainingWeight < 0) return INT_MIN;
    if(i==weights.size()) return 0;

    //Pick the ith item
    int opt1 = values[i] + knapsackHelper(i+1,weights, values, remainingWeight-weights[i]);

    //Ignore the ith item
    int opt2 = knapsackHelper(i+1, weights, values, remainingWeight);

    return max(opt1, opt2);

}

int main()
{
    int n;
    cout<<"Enter number of items : ";
    cin>>n;
    vector<int> weights(n), values(n);
    cout<<"Enter the weights and their values : ";
    for(int i=0; i<n; i++) {
        cin>>weights[i]>>values[i];
    }
    int capacity;
    cout<<"Enter Capacity of the knapsack : ";
    cin>>capacity;
    cout<<knapsackHelper(0, weights, values, capacity);
}