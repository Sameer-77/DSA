
--------------------------------------------------------------------  QUEUE IMPLEMENTATION USING ARRAY ----------------------------------------------------------------------------------------------------------------------
  ____________________________________________________________________________________________________________________________________________________________________________________________________________


#include <bits/stdc++.h>
using namespace std;

class Q {
    public:
    int *arr;
    int front, rear, size, capacity;

    Q(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front = rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return (size == 0);
    }

    bool isFull() {
        return (size == capacity);
    }

    void push(int x) {
        if (isFull()) {
            cout << "Queue full.." << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = x;

        if (front == -1) {
            front = rear;
        }

        size++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue empty.." << endl;
            return;
        }

        if (front == rear) {
            front = rear = -1;  // Queue becomes empty
        } else {
            front = (front + 1) % capacity;
        }

        size--;
    }

    int start() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    ~Q() {
        delete[] arr;  // Clean up dynamically allocated memory
    }
};

int main() {
    Q q(5);
    q.push(5);
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(1);
    q.push(0); // This will indicate the queue is full
    cout << "Front: " << q.start() << endl;
    cout << "Is Empty: " << q.isEmpty() << endl;

    q.pop();
    q.pop();
    cout << "Front after pops: " << q.start() << endl;

    return 0;
}
