#include<bits/stdc++.h>
using namespace std;
struct Node{
        int data;
        Node*next;
        Node(int val)
        {
            data=val;
            next=NULL;
        }
};
Node* convert2array(vector<int>&a )
{
    Node *head =new Node(a[0]);
    Node *mover =head;
    for(int i=1;i<a.size();i++)
    {
        Node*temp=new Node(a[i]);
        mover ->next=temp;
        mover=mover->next;
    }
    return head;
}
int main () 
{
    vector<int> a={4,5,6,7,8,8,1,2};
    cout<<convert2array(a);
}