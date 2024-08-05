
The "upper bound" in the context of binary search or sorted arrays is defined as follows:

Upper Bound:
->The upper bound of a given value in a sorted array is the smallest index at which an element greater than the given value can be inserted without disrupting the order of the array.
->In simpler terms, it is the first position where an element larger than the specified value can be found in the array.
->If no such element exists, the upper bound points to the position one past the last element in the array.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------
  Link : https://bit.ly/3IoKGce

#include<iostream>
#include<vector>
using namespace std;

int UpperBound(vector<int> arr, int n, int x) {
	// Write your code here
	int ans=n;
	int l=0, h=n-1;
	while(l<=h){
		int mid=(l+h)/2;
		if(arr[mid]>x){
			ans=mid;
			h=mid-1;
		}
		else{
			l=mid+1;
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
    cout<<"Enter the element to find upper bound: ";
    cin>>element;
    cout<<endl;
    cout<<"Element's upper bound index is "<<UpperBound(arr,n, element);
}
