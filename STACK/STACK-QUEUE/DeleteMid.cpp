#include <bits/stdc++.h>
using namespace std;

void del(int i, stack<int> &st, int mid)
{
    if (i == mid)
    {
        st.pop();
        return;
    }
    int temp = st.top();
    st.pop();
    del(i + 1, st, mid);
    st.push(temp);
}

void deleteMiddle(stack<int> &st)
{
    int mid = st.size() / 2;
    del(0, st, mid);
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    deleteMiddle(st);

    cout << "Stack after deletion of mid : ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}