#include<bits/stdc++.h>
using namespace std;
vector<int>  bubble_sort (vector<int> &a)
{
    for(int i=0;i<a.size()-1;i++)
    {
        for(int j=0;j<a.size();j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
    return a;
}
int main () 
{
    vector<int> a={1,5,2,1,3,5};
    vector<int> sorted=bubble_sort(a);
    for(int i=0;i<sorted.size();i++)
    {
        cout<< sorted[i]<<" ";
    }
    return 0;
}