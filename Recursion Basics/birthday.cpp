#include<bits/stdc++.h>
using namespace std;

void printBirthday(int n) {
    if(n==0) {
        cout<<"Happy Birthday.."<<endl;
        return;
    }
    cout<<n<<" days left for birthday"<<endl;
    printBirthday(n-1);
}

int main()
{
    int n;
    cout<<"Number of days left for birthday : ";
    cin>>n;
    printBirthday(n);
}