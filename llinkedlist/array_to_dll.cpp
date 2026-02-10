#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node* next;
        node *curr;
    node(int data1, node* prev1 = nullptr, node* next1 = nullptr)
    {
        data=data1;
        next=next1;
        curr=prev1;
    }
};
node * convertarr2DLL(vector<int> &a)
{
    node *head=new node(a[0]);
    node * curr=head;

    for(int i=1;i<a.size();i++)
    {
        node * temp=new node(a[i]);
        curr->next=temp;
        temp->curr=curr;
        curr=temp;
    }
    return head;
}
node * insert_at_head(node * head ,int element)
{
    node *newhead=new node (element);
    head->curr=newhead;
    return newhead;
}
node * insert_at_tail(node*head, int element )
{
    node *temp=head;
    node * curr=NULL;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        curr=temp->curr;
    }
    node *newelement=new node (element);
    curr->next=newelement;
    newelement->curr=curr;
    newelement->next=temp;
    return head;
}
int main () 
{
    vector<int> a={1,4,5,6,67,6};
    node *tempp=convertarr2DLL(a);
    node *print= insert_at_head(tempp,10);
    node *print_insert_tail=insert_at_tail(tempp,11);
    while(print!=NULL)
    {
        cout<< print_insert_tail->data <<" ";
        print_insert_tail=print_insert_tail->next;
    }
    return 0;
}  