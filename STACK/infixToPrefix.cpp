
-------------------------------------------*****INFIX TO PREFIX CONVERSION*******-----------------------------------------------------------------------------------

  ___________________________________________________________________________________________________________________________________________________________________






#include<bits/stdc++.h>
using namespace std;

int priority(char c) {
    if(c=='^') return 3;
    else if(c=='*' || c=='/') return 2;
    else if(c=='+' || c=='-') return 1;
    else return -1;
}
int main()
{
    string str;
    cout<<"Enter the infix expression : ";
    cin>>str;
    string ans="";

    stack<char> st;

    reverse(str.begin(), str.end());
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(')
            str[i] = ')';
        else if (str[i] == ')')
            str[i] = '(';
    }
    for(int i=0; i<str.size(); i++){
        if((str[i]>='A' && str[i]<='Z') || 
           (str[i]>='a' && str[i]<='z') || 
           (str[i]>='0' && str[i]<='9')) {
            ans += str[i];
        }
        else {
           if(str[i]=='('){
            st.push(str[i]);
           }
           else if(str[i]==')') {
            while(!st.empty() && st.top()!='(') {
                ans+=st.top();
                st.pop();
            }
            st.pop();
           }
           else {
            if(str[i]=='^') {
                while(!st.empty() && priority(str[i]) <= priority(st.top())) {
                    ans +=st.top();
                    st.pop();
                }
            }
            else {
                while(!st.empty() && priority(str[i]) < priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(str[i]);
           }
        }

    }
    while(!st.empty()) {
        ans+=st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    cout<<"The prefix expression is : "<<ans;
}
