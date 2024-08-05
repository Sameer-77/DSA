
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length)
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.


Link : https://leetcode.com/problems/search-in-rotated-sorted-array/description/


__________________________________________________________________________________________________________________________________________________________________





#include<iostream>
#include<vector>
using namespace std;

int searchInRotatedSortedArray(vector<int>& nums, int target){
    int l=0, h=nums.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<nums[l]){
                if(target>=nums[mid] && target<=nums[h]){
                    l=mid+1;
                }
                else{
                    h=mid-1;
                }
            }
            else{
                if(nums[mid]>=nums[l]){
                    if(nums[mid]>=target && nums[l]<=target){
                        h=mid-1;
                    }
                    else {
                        l=mid+1;
                    }
                }
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
    int element;
    cout<<"Enter the search element: ";
    cin>>element;
    cout<<endl;
    cout<<"Element is at index "<<searchInRotatedSortedArray(arr,element);
}
