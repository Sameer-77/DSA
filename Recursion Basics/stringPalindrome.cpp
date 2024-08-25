#include<bits/stdc++.h>
using namespace std;



string checkPalindrome(string &str, int l, int r) {
if(l>=r) return "YES";
if(str[l]!=str[r]) return "NO";
return checkPalindrome(str,++l,--r);
}

int main()
{
    string str;
    cout<<"Enter string : ";
    cin>>str;
    cout<<"IS THE GIVEN STRING PALINDROME : "<<checkPalindrome(str,0,str.size()-1);
}
