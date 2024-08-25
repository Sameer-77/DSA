#include<bits/stdc++.h>
using namespace std;

int findFactorial(int n) {
    if(n==0) return 1;
    return n*findFactorial(n-1);
}
int main()
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    cout<<findFactorial(n);
} 