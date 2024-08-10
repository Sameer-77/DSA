

Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.


Link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

__________________________________________________________________________________________________________________________________________________________________

#include<bits/stdc++.h>
using namespace std;


int MinElementInRotatedSortedArray(vector<int>&arr){
    int l=0, h=arr.size()-1;
    int ans=INT_MAX;
    while(l<=h){
        int mid=(l+h)/2;
        if(arr[mid]>=arr[l]){
            ans=min(ans,arr[l]);
            l=mid+1;
        }
        else{
            h=mid-1;
            ans=min(ans,arr[mid]);
        }
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Array size: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter Array elements in rotated format: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<endl;
    cout<<"Array elements are: ";
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Minimum element is "<<MinElementInRotatedSortedArray(arr);
}
