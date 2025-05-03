#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int *arr;
    int stackSize;
    int top;

    Stack(int n)
    {
        arr = new int[n];
        this->stackSize = n;
        top = -1;
    }
    void push(int num)
    {
        if (top == stackSize - 1)
        {
            cout << "Overflow...";
            return;
        }
        top++;
        arr[top] = num;
        stackSize++;
        cout << "Pushed " << num << endl;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Underflow...";
            return;
        }
        cout << "Popped : " << arr[top] << endl;
        top--;
        stackSize--;
    }

    void isEmpty()
    {
        string empty = "";
        if (top == -1)
        {
            empty = "YES";
        }
        else
        {
            empty = "NO";
        }
        cout << "Is Empty : " << empty << endl;
        return;
    }

    void size()
    {
        cout << "Stack size is : " << top + 1 << endl;
        return;
    }
    void peek()
    {
        if (top == -1)
        {
            cout << "Stack is Empty..." << endl;
        }
        else
        {
            cout << "Peek element is " << arr[top] << endl;
        }
    }
};

int main()
{
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.size();
    st.peek();
    st.pop();
    st.peek();
    st.isEmpty();
    st.size();
    st.pop();
    st.peek();
}