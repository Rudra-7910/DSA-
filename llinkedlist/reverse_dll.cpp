#include<bits/stdc++.h>
using namespace std;
class node {
    public:
    int data;
    node * prev;
    node * next;
    node (int data1,node * prev1=nullptr, node * next1=nullptr)
    {
        data=data1;
        prev=prev1;
        next=next1;
    }
};
node* convert2DLL(vector<int> &a)
{
    node * head= new node (a[0]);
    node * prev=head;
    for(int i=1;i<a.size();i++)
    {
        node * temp= new node ( a[i]);
        prev->next=temp;
        temp->prev=prev;
        prev=temp;
    }
    return head;
}
node * reverse(node * head ,vector<int> a)
{
    node * curr=head;
    while(curr!=NULL)
    {
        node * temp=curr->next;
        curr->next=curr->prev;
        curr->prev=temp;
        head=curr;
        curr=temp;
    }
    return head;
}

int main () 
{
    vector<int> a={1,2,3,4,5};
    node * head=convert2DLL(a);
    node *head1(reverse(head,a));
    node * temp=head1;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}