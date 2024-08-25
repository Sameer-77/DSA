#include<bits/stdc++.h>
using namespace std;
int FindSum(int n) {
    if(n==0) return n;
    return FindSum(n-1)+n;
}
int main()
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    cout<<FindSum(n);
}