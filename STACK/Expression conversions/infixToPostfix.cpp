

*********************************--------INFIX TO POSTFIX CONVERSION----------------************************************************************************************************


  ____________________________________________________________________________________________________________________________________________________________________





#include<bits/stdc++.h>
using namespace std;


int priority(char c)
{
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='-' || c=='+'){
        return 1;
    }
    return -1;
}
int main()
{
    string s;
    cout<<"Enter the expression : ";
    cin>>s;
    string ans="";
    stack<char> st;
    for(int i=0; i<s.size(); i++){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            ans+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && priority(s[i]) <= priority(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }

    cout<<"Resultant postfix expression is : "<<ans;
}
