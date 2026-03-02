#include<bits/stdc++.h>
using namespace std;
class node {
    public:
    int data;
    node * next;
    node(int data1,node*next1=nullptr)
    {
        data=data1;
        next=next1;
    }
};
node* convert2ll(vector<int> &a)
{
    node * head= new node (a[0]);
    node*curr=head;
    for(int i=1;i<a.size();i++)
    {
        node * temp= new node(a[i]);
        curr->next=temp;
        curr=curr->next;
    }
    return head;
}
void printingLL(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
node * finding(node*head , int k)
{
    node*temp=head;
    int count=0;
    while(temp!=NULL)
    {
        if(count==k)
        {
            return temp;
        }
        count=count+1;
        temp=temp->next;
    }
    return temp;
}
node * rotating_LL(node*head,int k)
{
    node*temp=head;
    int count=1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        count=count+1;
    }
    if(k%count==0)
    {
        return head;
    }
    k=k%count;
    temp->next=head;
    node*newLastNode= finding(head,count-k);
    head=newLastNode->next;
    newLastNode->next=NULL;
    return head;

}
int main ( )
{
    vector<int> a={1,2,3,4,5};
    node* head=convert2ll(a);
    node*neww =rotating_LL(head,4);
    printingLL(neww);
}