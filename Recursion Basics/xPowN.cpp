#include<bits/stdc++.h>
using namespace std;
long long findPow(int x, int n) {
    if(n==0) return 1;
    if(n==1) return x;
    long long partialAns = findPow(x,n-1);
    return x*partialAns;
}
int main()
{
    int x;
    cout<<"Enter x : ";
    cin>>x;
    int n;
    cout<<"Enter n : ";
    cin>>n;
    cout<<findPow(x,n);
}