

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].

Link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/


---------------------------------------------------------------------------------------------------------------------------------------------------------------






#include<iostream>
#include<vector>
using namespace std;


int firstOccurnence(vector<int>& nums, int target){
     int first=-1;
        int l=0, h=nums.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target){
                first=mid;
                h=mid-1;
            }
            else if(nums[mid]>target){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return first;
}
int LastOccurence(vector<int>& nums, int target){
    int last=-1;
        int l=0,h=nums.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target){
                last=mid;
                l=mid+1;
            }
            else if(nums[mid]>target){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return last;
}
vector<int> firstAndLastOccurence(vector<int>& nums, int target){
    int first = firstOccurnence(nums,target);
    if(first==-1) return {-1,-1};
    int last= LastOccurence(nums, target);
    return {first,last};
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
    cout<<"First and Last occurence : ";
    vector<int> ans = firstAndLastOccurence(arr,target);
    cout<<ans[0]<<" "<<ans[1];
}
