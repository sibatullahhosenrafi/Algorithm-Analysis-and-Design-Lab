#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>price(n+1,0);
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
    cout<<dp[n]<<endl;
    int curr=n;
    while(curr>0)
    { // index;
        cout<<cut[curr]<<" ";
        curr-=cut[curr];
    }cout<<endl;

}
