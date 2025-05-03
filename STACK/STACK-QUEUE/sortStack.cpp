#include <bits/stdc++.h>
using namespace std;

void insertSorted(stack<int> &st, int num)
{
    if (st.empty() || (st.top() < num))
    {
        st.push(num);
        return;
    }
    int temp = st.top();
    st.pop();
    insertSorted(st, num);
    st.push(temp);
}

void sortStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int num = st.top();
    st.pop();
    sortStack(st);
    insertSorted(st, num);
}

int main()
{
    stack<int> st;
    st.push(5);
    st.push(-2);
    st.push(9);
    st.push(-7);
    st.push(3);
    sortStack(st);
    cout << "Sorted stack : ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

//------------------------------------------------------------------------------------------------------------------------------------

// #include <bits/stdc++.h>
// using namespace std;

// void insertInOrder(stack<int> &st, int num)
// {
//     if (st.empty() || st.top() <= num)
//     {
//         st.push(num);
//         return;
//     }
//     int temp = st.top();
//     st.pop();
//     insertInOrder(st, temp);
//     st.push(temp);
// }

// void sortStack(stack<int> &st)
// {
//     if (st.empty())
//     {
//         return;
//     }
//     int temp = st.top();
//     st.pop();
//     sortStack(st);
//     insertInOrder(st, temp);
// }

// int main()
// {
//     stack<int> st;
//     st.push(30);
//     st.push(20);
//     st.push(40);
//     st.push(-3);
//     st.push(9);
//     // cout << "Stack before sorting : ";
//     // while (!st.empty())
//     // {
//     //     cout << st.top() << " ";
//     //     st.pop();
//     // }
//     // cout << endl;
//     sortStack(st);
//     cout << "Stack after sorting : ";
//     while (!st.empty())
//     {
//         cout << st.top() << " ";
//         st.pop();
//     }
// }