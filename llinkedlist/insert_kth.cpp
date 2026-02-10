#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *next;
    node (int val)
    {
        data=val;
        next=NULL;
    }
};
node *conver2ll(vector<int> a)
{
    node * head=new node(a[0]);
    node *mover =head;
    for(int i=1;i<a.size();i++)
    {
        node * temp=new node (a[i]);
        mover->next=temp;
        mover=mover->next;
    }
    return head;
}
node *insert_at_k(node*head,int element,int k)
{
    int count=1;
    if(count==1)
    {
        node*temp=new node(element);
        temp->next = head;
        return temp;
    }
    node *temp=head;
    while(temp!=NULL)
    {
        if(count==k-1)
        {
            node *x=new node(element);
            x->next=temp->next;
            temp->next=x;
            break;
        }
        count=count+1;
        temp=temp->next;
    }
    return head;
}
void printing(node*head)
{
    node * temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
    }
}
int main ()
{
    vector<int>a={2,0,1,8,5};
    node *head=conver2ll(a);
    node*head1=insert_at_k(head,4,1);
    printing(head1);
}