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

int main()
{
    stack<int> st;
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    int el;
    cout << "Enter the element to push at the bottom of the stack : ";
    cin >> el;
    insertBottom(st, el);
    cout << "Stack after pushing the element at the bottom : ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}