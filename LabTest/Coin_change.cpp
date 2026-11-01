#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>coins(n);
    for(int i=0;i<n;i++)cin>>coins[i];
    int w;
    cin>>w;
    const int INF=1e9;
    vector<int>dp(w+1,INF),parent(w+1,-1);
    dp[0]=0;

    for(int i=1;i<=w;i++)
    {
        for(int c:coins)
        {
            if(i-c>=0&&dp[i-c]!=INF&&dp[i-c]+1<dp[i])
            {
                dp[i]=dp[i-c]+1;
                parent[i]=c;
            }
        }
    }
    if(dp[w]==INF)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    cout<<dp[w]<<endl;
    int curr=w;
    while(curr>0)
    {
        cout<<parent[curr]<< " ";
        curr-=parent[curr];
    }
    cout<<endl;
    return 0;
}

