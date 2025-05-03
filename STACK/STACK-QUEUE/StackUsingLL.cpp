#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *next;
    int val;

    Node(int data)
    {
        this->val = data;
        next = NULL;
    }
};

class Stack
{
public:
    Node *top;
    int size;

    Stack()
    {
        size = 0;
        top = NULL;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        cout << "Pushed : " << data << endl;
        size++;
    }
    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow...";
        }
        else
        {
            Node *temp = top;
            top = top->next;
            cout << "Popped : " << temp->val << endl;
            delete temp;
            size--;
        }
    }
    void isEmpty()
    {
        if (top == NULL)
        {
            cout << "Is Empty : YES" << endl;
        }
        else
        {
            cout << "Is empty : NO " << endl;
        }
    }

    void peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Peek element is " << top->val << endl;
        }
    }
};

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.peek();
    st.push(30);
    st.push(40);
    st.pop();
    st.peek();
}