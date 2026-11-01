#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>a(n);
int crss(int si,int mid,int ei)
{
    int lsubs=INT_MIN;
    int rsubs=INT_MIN;
    int sum=0;
    for(int i=mid; i>=0;i--)
    {
      sum+=a[i];
      if(lsubs<sum)
            lsubs=sum;
    }
    sum=0;
    for(int i=mid+1;i<n;i++)
    {
        sum+=a[i];
        if(rsubs<sum)
        {
            rsubs=sum;
        }
    }
    return lsubs+rsubs;

}
int mss(int si,int ei)
{
    if(si==ei)
        return a[si];
    int mid=(si+ei)/2;
    int lss=mss(si,mid);
    int rss=mss(mid+1,ei);
    int css=crss(si,mid,ei);
    return max({lss,rss,css});
}
int main()
{
    cin>>n;
    a.resize(n);
    for(int i=0; i<n; i++)cin>>a[i];

cout<<mss(0,n)<<endl;
  /*
  8
-2 -5 6 -2 -3 1 5 -6
  */

}
