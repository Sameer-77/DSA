


//Probem link : https://bit.ly/43967G5


Definition:
For a given value x in a sorted array arr, the lower bound is the smallest index i such that arr[i] >= x.



  
#include <iostream>
#include<vector>
using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int ans=n;
	int l=0, h=n-1;
	while(l<=h){
		int mid=(l+h)/2;
		if(arr[mid]>=x){
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
    cout<<"Enter the element to find lower bound: ";
    cin>>element;
    cout<<endl;
    cout<<"Element's lower bound index is "<<lowerBound(arr,n, element);
}
