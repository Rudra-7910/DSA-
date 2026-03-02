#include<bits/stdc++.h>
using namespace std;
class node 
{
    public:
    int data;
    node * prev;
    node * next;
    node (int data1 , node * next1=nullptr, node * prev1=nullptr)
    {
        data = data1;
        prev=prev1;
        next=next1;
    }
};
node * convert2DLL ( vector<int> & a)
{
    node * head= new node (a[0]);
    node * prev=head;
    for(int i=1;i<a.size();i++)
    {
        node * temp=new node (a[i]);
        prev->next=temp;
        temp->prev=prev;
        prev=temp;
    }
    return head;
}
void printing (node*head)
{
    node * temp= head;
    while(temp!=0)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
node * reverse ( node * head)
{
    node * curr= head;
    //node * prev=head;
    while(curr!=NULL)
    {
        node * temp= curr->next;
        curr->next=curr->prev;
        curr->prev=temp;
        head=curr;
        curr=temp;
    }
    return head;
}
node * insert_at_kth_position(node * head,int element, int k)
{
    node * curr=head;
    int count=1;
    if (k == 1)
    {
        node* newNode = new node(element);
        newNode->next = head;
        if (head != NULL)
        head->prev = newNode;
        return newNode;
    }
    while(curr!=NULL)
    {
        if(count==k-1)
        {
            node * newNode=new node ( element);
            node*temp=curr->next;
            newNode->next=curr->next;
            curr->next=newNode;
            if(temp!=NULL)
            {
                temp->prev=newNode;
            }
            newNode->prev=curr;
            break;
        }
        curr=curr->next;
        count++;
    }
    return head;
}
node * insert_at_head(node * head, int element)
{
    node *newNode= new node (element);
    newNode->next=head;
    newNode->prev=NULL;
    return newNode;
}
node * remove_head(node *head, int element)
{
    node*NewHead= new node ( element);
    node * temp=head->next;
    NewHead->next=temp;
    NewHead->prev=NULL;
    delete (head);
    return NewHead;
}
node* remove_from_end(node * head , int k)
{
    node * fast=head;
    node * slow=head;
    for(int i=1;i<=k;i++)
    {
        fast=fast->next;
    }
    while(fast->next!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    node * remove=slow->next;
    slow->next=slow->next->next;
    delete remove;
    return head;
}
int main () 
{
    vector<int> a={1,2,3,4,5};
       node * printiing= convert2DLL(a);
//   //  node* reversing=reverse(printiing); 
//     node * inserting = insert_at_kth_position(printiing,5,3);
//    // printing(reversing);
//     printing(inserting);
    // node *inserting_at_head=insert_at_head(printiing,5);
    // printing(inserting_at_head);
    node * end_remove=remove_from_end(printiing, 2);
    printing(end_remove);
    return 0;
}
