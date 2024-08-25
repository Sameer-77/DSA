#include<bits/stdc++.h>
using namespace std;

int countVow(string s, int i) {
    if(i<0) {
        return 0;
    }
    if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') {
        return 1+countVow(s,i-1);   
    }
    else {
        return countVow(s,i-1);
    }

}

int main()
{
    string str;
    cout<<"Enter string : ";
    cin>>str;
    cout<<"Num of vowels : "<<countVow(str,str.size());
}