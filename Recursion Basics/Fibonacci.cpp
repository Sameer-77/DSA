#include<bits/stdc++.h>
using namespace std;
int findFib(int n) {
    if(n==1 || n==2) return 1;
    return findFib(n-1)+findFib(n-2);
}
int main()
{
    int n;
    cout<<"Enter nth term to find it's fibonacci val : ";
    cin>>n;
    cout<<findFib(n);
}