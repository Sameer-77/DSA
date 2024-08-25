#include<bits/stdc++.h>
using namespace std;

void printEven(int n) {
    if(n==2) {
        cout<<2<<" ";
        return;
    }
    printEven(n-2);
    cout<<n<<" ";
}

int main() 
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    if(n%2==1) n--;
    printEven(n);
}