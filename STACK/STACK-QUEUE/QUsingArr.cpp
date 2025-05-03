#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int *arr;
    int front;
    int rear;
    int currSize;
    int capacity;

    Queue(int n)
    {
        arr = new int[n];
        front = -1;
        this->capacity = n;
        rear = -1;
        currSize = 0;
    }

    void push(int data)
    {
        if (front == -1 && rear == -1)
        {
            front = 0, rear = 0;
            arr[front] = data;
            cout << "Pushed " << data << endl;
            currSize++;
        }
        else if (currSize == capacity)
        {
            cout << "Queue is full...\n";
        }
        else
        {
            rear = (rear + 1) % capacity;
            arr[rear] = data;
            cout << "Pushed " << data << endl;
            currSize++;
        }
    }

    void pop()
    {
        if (rear == -1 && front == -1)
        {
            cout << "Queue is empty..." << endl;
        }
        else
        {
            cout << "Popped " << arr[front] << endl;
            front = (front + 1) % capacity;
            currSize--;
        }
    }

    void qSize()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Q is empty " << endl;
        }
        else
        {
            cout << "Q size is " << currSize << endl;
        }
    }

    void Front()
    {
        if (rear == -1 && front == -1)
        {
            cout << "Queue is empty...\n";
        }
        else
        {
            cout << "Front Element is " << arr[front] << endl;
        }
    }
};

int main()
{
    Queue q(5);
    q.qSize();
    q.Front();
    q.push(10);
    q.push(20);
    q.qSize();
    q.push(30);
    q.push(40);
    q.qSize();
    q.push(50);
    q.pop();
    q.qSize();
    q.pop();
    q.Front();
    q.qSize();
    q.push(60);
    q.qSize();
    q.Front();
}