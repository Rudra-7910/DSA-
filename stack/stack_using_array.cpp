#include<bits/stdc++.h>
using namespace std;
class ArrayStack{
    public:
    int topIndex=-1;
    int curr_size=0;
    int st[10];
    void push(int x)
    {
        if(topIndex>=9)
        {
            cout<<"Stack Overflow"<<endl;
            return ;
        }
        topIndex++;
        st[topIndex]=x;
        curr_size++;
    }
    int pop ()
    {
        if(topIndex==-1)
        {
            cout<<"Stack is Empty"<<endl;
            return -1 ;
        }
        curr_size--;
        return st[topIndex--];
    }
    int size()
    {
        return curr_size;
    }
    int top()
    {
        if(topIndex == -1)
    {
        cout<<"Stack is Empty"<<endl;
        return -1;
    }
    return st[topIndex];
    }
};
int main () 
{
    ArrayStack stack;
    stack.push(3);
    stack.push(4);
    cout<<stack.top()<<endl;
    cout<<stack.pop()<<endl;
    cout<<stack.size()<<endl;
    cout<<stack.pop()<<endl;
    cout<<stack.pop()<<endl;
    
}