#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        next = NULL;
    }
};

class Queue
{
public:
    Node *front;
    Node *rear;
    int currSize;

    Queue()
    {
        front = rear = NULL;
        currSize = 0;
    }

    bool isEmpty()
    {
        return front == NULL;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);
        if (rear == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        currSize++;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty..\n";
            return;
        }

        Node *temp = front;
        cout << "Popped " << temp->val << endl;
        front = front->next;
        delete temp;
        currSize--;

        if (front == NULL) // If queue becomes empty, reset rear
        {
            rear = NULL;
        }
    }

    int size()
    {
        return currSize;
    }
};

int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    cout << "Q size is : " << q.size() << endl;
    q.pop();
    q.push(20);
    q.push(30);
    cout << "Q size is : " << q.size() << endl;
    q.pop();
    cout << "Q size is : " << q.size() << endl;

    return 0;
}
