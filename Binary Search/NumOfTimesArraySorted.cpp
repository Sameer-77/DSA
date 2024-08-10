
Problem statement
You are given an array 'arr' having 'n' distinct integers sorted in ascending order. The array is right rotated 'r' times
Find the minimum value of 'r'.
Right rotating an array means shifting the element at 'ith' index to (‘i+1') mod 'n' index, for all 'i' from 0 to ‘n-1'.
Example:
Input: 'n' = 5 , ‘arr’ = [3, 4, 5, 1, 2]
Output: 3 
Explanation:
If we rotate the array [1 ,2, 3, 4, 5] right '3' times then we will get the 'arr'. Thus 'r' = 3.

  Link : https://bit.ly/3pMzTCh

___________________________________________________________________________________________________________________________________________________________________


#include<bits/stdc++.h>
using namespace std;


int HowManyTimesArraySorted(vector<int>&arr){
    int l=0, h=arr.size()-1;
    int ans=INT_MAX;
    int ind=-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(arr[l]<=arr[h]){
            if(arr[l]<ans){
                ans=arr[l];
                ind=l;
            }
            break;
        }
        if(arr[l]<=arr[mid]){
            if(arr[l]<ans){
                ans=arr[l];
                ind=l;
            }
            l=mid+1;
        }
        else{
            if(arr[mid]<ans){
                ans=arr[mid];
                ind=mid;
            }
        }
    }

    return ind;
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
    cout<<"Number of times array rotated : "<<HowManyTimesArraySorted(arr);
}
