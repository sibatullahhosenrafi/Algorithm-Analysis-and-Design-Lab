#include<bits/stdc++.h>
using namespace std;
int a[105];
int n;
void mg(int l,int mid,int r)
{
    vector<int>temp;
    int i=l;
    int j=mid+1;
    while(i<=mid&j<=r)
    {
        if(a[i]<=a[j])
        {
            temp.push_back(a[i]);
            i++;
        }
        else
        {
            temp.push_back(a[j]);
            j++;
        }

    }
    while(i<=mid)
    {
        temp.push_back(a[i]);
        i++;
    }
    while(j<=r)
    {
        temp.push_back(a[j]);
        j++;
    }
    for(int k=0; k<temp.size(); k++)
    {
        a[l+k]=temp[k];
    }
}
void mergeSort(int l,int r)
{
    if(l>=r)
        return;
    int mid=(l+r)/2;
    mergeSort(l,mid);
    mergeSort(mid+1,r);
    mg(l,mid,r);
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    mergeSort(0,n-1);
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
}
 
