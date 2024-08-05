

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, 
return the index where it would be if it were inserted in order.

Link : https://leetcode.com/problems/search-insert-position/description/

-------------------------------------------------------------------------------------------------------------------------------------------------------------


#include<iostream>
#include<vector>
using namespace std;

int SearchInsertPosition(vector<int>&arr, int target) {
	// Write your code here
	int n=arr.size();
    int l=0, h=n-1;
    while(l<=h){
        int mid=(l+h)/2;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid]>target){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
            
        }
        return l;
    }
}


int main()
{
    int n;
    cout<<"Array size: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Array elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<endl;
    cout<<"Array: ";
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int target;
    cout<<"Enter the element to be inserted: ";
    cin>>target;
    cout<<endl;
    cout<<"Position where the element to be inserted is "<<SearchInsertPosition(arr,target);
}
