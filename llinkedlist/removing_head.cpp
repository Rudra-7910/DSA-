#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node*next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};
node* convert2ll(vector<int> &a)
{
    node * head=new node(a[0]);
    node *mover=head;
    for(int i=1;i<a.size();i++)
    {
        node* temp= new node(a[i]);  //temp= new node /-
        mover->next=temp;   // current mover ke next pe null ki jgh temp (new node ) ka address dal diya
        mover=mover->next;  //mover ko next pr leke gya 
    }
    return head;
}
void printing(node*head)
{
    node * mover=head;
    //cout<<"priting array as linkedlist " <<endl;
    while(mover!=NULL )
    {
        cout << mover->data<<" "<<endl;
        mover=mover->next;
    }
}
node * removing_head(node*head)
{
    node *temp=head;
    head=head->next;
    delete temp;
    return head;
}
node * removing_kth_element(node*head,int k)
{
    int cnt=1;
    node*temp=head;
    node *pre=NULL;
    while(temp!=NULL)
    {
        if(cnt==k)
        {
            pre->next=pre->next->next;
            delete(temp);
            break;
        }
        pre=temp;
        temp=temp->next;
        cnt++;
    }
    return head;
}
int main () 
{
    vector<int> a={2,0,1,8,5};
    node*head=convert2ll(a);
   // node*head1=removing_head(head);
   // printing(head1);
    //printing(head);
    node*head2=removing_kth_element(head,2);
    printing(head2);

}