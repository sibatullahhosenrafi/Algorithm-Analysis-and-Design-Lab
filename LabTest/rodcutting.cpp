#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>price(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>price[i];
    }
    vector<int>dp(n+1,0),cut(n+1,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(price[j]+dp[i-j]>dp[i])
            {
                dp[i]=price[j]+dp[i-j];
                cut[i]=j;
            }
        }
    }
    cout<<"Max profit"<<endl;
    cout<<dp[n]<<endl;
    int cur=n;
    cout<<"Index of Price"<<endl;
    while(cur>0)
    {
        cout<<cut[cur]<<" ";
        cur-=cut[cur];
    }
    cout<<endl;
}
