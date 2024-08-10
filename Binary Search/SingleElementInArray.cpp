
Problem statement
You are given a sorted array ‘arr’ of ‘n’ numbers such that every number occurred twice in the array except one, which appears only once.
Return the number that appears once.

Link : https://bit.ly/42KKHj5

___________________________________________________________________________________________________________________________________________________________________
#include<bits/stdc++.h>
using namespace std;

int SingleElementInAnArray(vector<int>&arr){
    int n=arr.size();
    if(n==1) return arr[0];
    if(n==2 && arr[0]!=arr[1]) return arr[0];
    if(arr[n-1]!=arr[n-2]) return arr[n-1];

    int low=1, high=n-2;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid]+1){
            return arr[mid];
        }
        //We are at left of the single element
        if((mid%2==1 && arr[mid]==arr[mid-1]) || (mid%2==0 && arr[mid]==arr[mid+1])){
            low = mid+1;
        }
        //We are on the right half of single element
        else{
            high = mid-1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout<<"Array size: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter Array elements : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<endl;
    cout<<"Array elements are: ";
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Single Element is : "<<SingleElementInAnArray(arr);
}
