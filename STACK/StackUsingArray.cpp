
----------------------------------------------------------------STACK IMPLEMENTATION USING ARRAYS---------------------------------------------------------------------------------------------------------------


  ___________________________________________________________________________________________________________________________________________________________________________________________________________________


#include<bits/stdc++.h>
using namespace std;

class Stack{
    int topIndex, size;
    int *st;
    public:
    Stack(int n){
        size=n;
        st = new int[n];
        topIndex=-1;
    }

    int siz(){
        return topIndex+1;
    }

    void push(int x){
        if(topIndex<size){
            topIndex++;
            st[topIndex] = x;
            return;
        }
        return;
    }

    int top(){
        if(topIndex==-1){
            return -1;
        }
        return st[topIndex];
    }

    void pop(){
        if(topIndex==-1) return;
        else{
            cout<<"Popped element is : "<<st[topIndex]<<endl;
            topIndex--;
        }
    }
};


int main()
{
    Stack s(10);
    s.push(100);
    s.push(90);
    s.push(80);
    s.push(70);
    s.push(60);
    s.push(50);
    s.push(40);
    s.push(30);
    cout<<"Size : "<<s.siz()<<endl;
    s.pop();
    cout<<"Size : "<<s.siz()<<endl;
    cout<<"Top element is : "<<s.top()<<endl;
}
