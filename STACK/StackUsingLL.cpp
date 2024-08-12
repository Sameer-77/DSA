


--------------------------------------STACK IMPLEMENTATION USING LINKED LIST-------------------------------------------------------------------------

  ____________________________________________________________________________________________________________________________________________________________





#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next=NULL;
    }
};

class Stack{
    public:
    Node* topInd;
    int numOfEl = 0;
    Stack(){
        topInd=NULL;
    }

    void push(int val){
        Node* newNode = new Node(val);

        // if(topInd == NULL){
        //     topInd = newNode;
        //     numOfEl++;
        // }
        newNode->next = topInd;
        topInd = newNode;
        numOfEl++;
    }

    void pop(){
        Node* temp = topInd;
        cout<<"Popped element is : "<<topInd->data<<endl;
        topInd = topInd->next;
        delete temp;
        numOfEl--;
    }

    int top(){
        if(topInd){
            return topInd->data;
        }
        return -1;
    }

    int size(){
        return numOfEl;
    }

};


int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout<<"Size : "<<st.size()<<endl;
    cout<<"Top : "<<st.top()<<endl;
    st.pop();
    cout<<"Size : "<<st.size()<<endl;
}
