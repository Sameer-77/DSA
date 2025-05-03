#include <bits/stdc++.h>
using namespace std;

void helper(string &s, int n, vector<string> &ans, int open, int close)
{
    if (open + close == 2 * n)
    {
        if (open == close && open == n)
        {
            ans.push_back(s);
        }
        return;
    }
    if (open < n)
    {
        s.push_back('(');
        helper(s, n, ans, open + 1, close);
        s.pop_back();
    }
    if (close < open)
    {
        s.push_back(')');
        helper(s, n, ans, open, close + 1);
        s.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    string s;
    int open = 0, close = 0;
    helper(s, n, ans, open, close);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the n value : ";
    cin >> n;
    vector<string> ans = generateParenthesis(n);
    cout << "All parenthesis\n";
    for (auto str : ans)
    {
        cout << str << endl;
    }
}
