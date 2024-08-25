#include<bits/stdc++.h>
#include<vector>
using namespace std;

void uniquePermutationsGenerator(vector<int> &arr, int pos, vector<vector<int>> &ans) {
    if(pos==arr.size()) {
        ans.push_back(arr);
        return;
    }
    unordered_set<int> st;

    for(int i=pos; i<arr.size(); i++) {
        if(st.find(arr[i])!=st.end()) continue;
        st.insert(arr[i]);
        swap(arr[i],arr[pos]);
        uniquePermutationsGenerator(arr,pos+1,ans);
        swap(arr[i],arr[pos]);
    }
}

void permutationPrinter(const vector<int> & subset) {
    cout<<"{";
    for(int i=0; i<subset.size(); i++) {
        cout<<subset[i]<<" ";
    }
    cout<<"}";
}

int main()
{
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array elements : ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    vector<vector<int>> ans;
    uniquePermutationsGenerator(arr,0,ans);
    cout << "Unique permutations are:" << endl;
    for (const auto &subset : ans) {
        permutationPrinter(subset);
        cout << endl;
    }
}