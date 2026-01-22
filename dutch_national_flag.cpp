#include<iostream>
#include<vector>
using namespace std;
int main () 
{
    int low=0;
    int mid=0;
    vector <int> a={1,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,0,0,0,0,0};
    int high= a.size()-1;
    while(mid<=high)
    {
        if(a[mid]==0)
        {
            swap(a[low],a[mid]);
            low++;
            mid++;
        }
        else if ( a[mid]==1)
        {
            mid++;
        }
        else if(a[mid]==2)
        {
            swap(a[mid],a[high]);
            high--;
        }
    }
        for(int i=0;i<a.size();i++)
        {
            cout<<a[i];
        }
    }