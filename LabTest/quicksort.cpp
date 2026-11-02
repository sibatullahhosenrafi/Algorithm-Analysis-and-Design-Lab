#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&a,int l,int r)
{
    int pivot=a[l];
    int i=l+1;
    int j=r;
    while(i<=j)
    {
        while(i<=r and a[i]<=pivot)i++;
        while(j>l and a[j]>pivot)j--;
        if(i<j) swap(a[i],a[j]);
    }
    swap(a[l],a[j]);
    return j;
}
void quicksort(vector<int>&a,int l,int r)
{
    if(l>=r) return;
    int p=partition(a,l,r);
    quicksort(a,l,p-1);
    quicksort(a,p+1,r);
}
int main()
{
    int n;
    cin>>n;
vector<int>a(n);
for(int i=0;i<n;i++)
{
    cin>>a[i];
}
   quicksort(a,0,a.size()-1);
   for(int x: a)cout<<x<<" ";
}
