
------------------------------------------------QUEUE IMPLEMENTATION USING LL-----------------------------------------------------------------------------------

  _______________________________________________________________________________________________________________________________________________________________




#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

class Q{
    Node* front;
    Node* rear;
    
    public:

    Q(){
        front=rear=NULL;
    }

    //Q is empty or not;
    bool isEmpty(){
        return front==NULL;
    }

    //PUSH
    void push(int x){
        cout<<"Pushed "<<x<<" into Queue "<<endl;
        if(isEmpty()){
            front = rear = new Node(x);
        }
        else{
            Node * temp = new Node(x);
            rear->next = temp;
            rear=rear->next;
        }
    }

    //POP
    void pop(){
        if(front==NULL){

            cout<<"Empty.."<<endl;
            return;
        }
        else{
            cout<<"Popped : "<<front->data<<endl;
            Node* temp=front;
            front=front->next;
            delete temp;
        }
    }

    //Front element
    int start(){
        if(isEmpty()) return -1;
        return front->data;
    }
};



int main()
{
    Q q;
    q.push(20);
    q.push(30);
    q.push(50);
    cout<<"Q's first element : "<<q.start()<<endl;
    q.pop();
    cout<<"Q's first element : "<<q.start()<<endl;
}
