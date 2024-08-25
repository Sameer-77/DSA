#include<bits/stdc++.h>
#include<vector>
using namespace std;

void subsetGenerator(int arr[], int i, vector<vector<int>>&ans, vector<int> subset, int n) {
    if(i==n) {
        ans.push_back(subset);
        return;
    }

    //Take ith element
    subset.push_back(arr[i]);
    subsetGenerator(arr,i+1,ans,subset,n);
    subset.pop_back();

    //Ignorre ith element
    subsetGenerator(arr, i+1, ans, subset, n);
}

void printVector(const vector<int> &vec) {
    cout<<"{";
    for(int i = 0; i < vec.size(); i++) {
        cout <<vec[i];
        if(i < vec.size() - 1) {
            cout << " "; // Add space between elements
        }
    }
    cout<<"}";
    cout<<" ";
}

int main()
{
    int n;
    cout<<"Enter array size : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements : ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    vector<vector<int>> ans;
    vector<int> subset;
    subsetGenerator(arr,0,ans,subset,n);

    cout<<"\nSubsets of the given array : ";
    for(const auto &subset : ans) {
        printVector(subset);
    }
}