#include <bits/stdc++.h>
using namespace std;

bool isValid(string &s)
{
    int n = s.size();
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (ch == '[' || ch == '{' || ch == '(')
        {
            st.push(ch);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            char c = st.top();
            st.pop();
            if (ch == ')' && c != '(' ||
                ch == ']' && c != '[' ||
                ch == '}' && c != '{')
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    string s;
    cout << "Enter the string : ";
    cin >> s;
    cout << "Is Valid : " << isValid(s);
}