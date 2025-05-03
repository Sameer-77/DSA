#include <bits/stdc++.h>
using namespace std;

void insertBottom(stack<int> &st, int el)
{
    if (st.empty())
    {
        st.push(el);
        return;
    }
    int temp = st.top();
    st.pop();
    insertBottom(st, el);
    st.push(temp);
}

void rev(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int temp = st.top();
    st.pop();
    rev(st);
    insertBottom(st, temp);
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    rev(st);
    cout << "Reversed stack : ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}