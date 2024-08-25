#include<bits/stdc++.h>
using namespace std;

void reverseArray(int arr[],int l, int r) {
    if(l>=r) return;
    swap(arr[l],arr[r]);
    return reverseArray(arr,l+1,r-1);
}

int main()
{
    int n;
    cout<<"Array size : ";
    cin>>n;
    int arr[n];
    cout<<"Enter Array elements : ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    cout<<"Original array : ";
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    reverseArray(arr,0,n-1);

    cout<<"\nReversed array : ";
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}